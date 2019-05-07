/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/01/19 11:57:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <libavutil/avutil.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

int main()
{
    AVOutputFormat *ofmt = NULL;
    //Input AVFormatContext and Output AVFormatContext
    AVFormatContext *ifmt_ctx = NULL, *ofmt_ctx = NULL;
    AVPacket pkt;
    const char *in_filename, *out_filename;
    int ret, i;
    int videoindex = -1;
    int frame_index = 0;

    in_filename = "rtsp://admin:admin12345@30.87.4.137:554/h264/ch1/main/av_stream";
    out_filename = "rtmp://127.0.0.1:1935/live/livestream";

    AVDictionary *options = NULL;
    // av_dict_set(&options, "buffer_size", "1024000", 0);
    // av_dict_set(&options, "max_delay", "500000", 0);
    // // 设置超时断开连接时间
    // av_dict_set(&options, "stimeout", "20000000", 0);
    // // 以udp方式打开，如果以tcp方式打开将udp替换为tcp
    // av_dict_set(&options, "rtsp_transport", "tcp", 0);

    //Input
    if ((ret = avformat_open_input(&ifmt_ctx, in_filename, 0, &options)) < 0)
    {
        printf("Could not open input file. in_filename(%s)\n", in_filename);
        goto end;
    }
    if ((ret = avformat_find_stream_info(ifmt_ctx, 0)) < 0)
    {
        printf("Failed to retrieve input stream information");
        goto end;
    }

    for (i = 0; i < ifmt_ctx->nb_streams; i++)
        if (ifmt_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            videoindex = i;
            break;
        }

    av_dump_format(ifmt_ctx, 0, in_filename, 0);

    //Output
    ret = avformat_alloc_output_context2(&ofmt_ctx, NULL, "rtsp", out_filename); //RTMP
    if (ret < 0) {
        return ret;
    }

    if (!ofmt_ctx)
    {
        printf("Could not create output context\n");
        ret = AVERROR_UNKNOWN;
        goto end;
    }
    ofmt = ofmt_ctx->oformat;
    for (i = 0; i < ifmt_ctx->nb_streams; i++)
    {
        //Create output AVStream according to input AVStream
        AVStream *in_stream = ifmt_ctx->streams[i];
        AVStream *out_stream = avformat_new_stream(ofmt_ctx, in_stream->codec->codec);
        if (!out_stream)
        {
            printf("Failed allocating output stream\n");
            ret = AVERROR_UNKNOWN;
            goto end;
        }
        //Copy the settings of AVCodecContext
        ret = avcodec_copy_context(out_stream->codec, in_stream->codec);
        if (ret < 0)
        {
            printf("Failed to copy context from input to output stream codec context\n");
            goto end;
        }
        out_stream->codec->codec_tag = 0;
        if (ofmt_ctx->oformat->flags & AVFMT_GLOBALHEADER)
            out_stream->codec->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
    }
    //Dump Format------------------
    av_dump_format(ofmt_ctx, 0, out_filename, 1);
    
    //Open output URL
    if (!(ofmt->flags & AVFMT_NOFILE))
    {
        ret = avio_open(&ofmt_ctx->pb, out_filename, AVIO_FLAG_WRITE);
        if (ret < 0)
        {
            printf("Could not open output URL '%s'", out_filename);
            goto end;
        }
    }

    AVDictionary *dict;
    av_dict_set(&dict, "rtsp_transport","tcp",0);
    av_dict_set(&dict, "muxdelay", "0.1", 0);
    ofmt_ctx->audio_codec_id = ofmt_ctx->oformat->audio_codec;
    ofmt_ctx->video_codec_id = ofmt_ctx->oformat->video_codec;
    //Write file header
    ret = avformat_write_header(ofmt_ctx, &dict);
    if (ret < 0)
    {
        printf("Error occurred when opening output URL\n");
        goto end;
    }

#if USE_H264BSF
    AVBitStreamFilterContext *h264bsfc = av_bitstream_filter_init("h264_mp4toannexb");
#endif

    int start_time = av_gettime();
    while (1)
    {
        AVStream *in_stream, *out_stream;
        //Get an AVPacket
        ret = av_read_frame(ifmt_ctx, &pkt);
        if (ret < 0)
            break;
        //printf("--1----=%8d------=%d-----------\n",pkt.pts, pkt.stream_index);
        in_stream = ifmt_ctx->streams[pkt.stream_index];
        out_stream = ofmt_ctx->streams[pkt.stream_index];
        /* copy packet */
        //Convert PTS/DTS
        pkt.pts = av_rescale_q_rnd(pkt.pts, in_stream->time_base, out_stream->time_base, (enum AVRounding)(AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX));
        pkt.dts = av_rescale_q_rnd(pkt.dts, in_stream->time_base, out_stream->time_base, (enum AVRounding)(AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX));

        pkt.duration = av_rescale_q(pkt.duration, in_stream->time_base, out_stream->time_base);
        pkt.pos = -1;
        //Print to Screen
        if (pkt.stream_index == videoindex)
        {
            //printf("Receive %8d video frames from input URL\n", frame_index);
            frame_index++;

#if USE_H264BSF
            av_bitstream_filter_filter(h264bsfc, in_stream->codec, NULL, &pkt.data, &pkt.size, pkt.data, pkt.size, 0);
#endif
        }
        //ret = av_write_frame(ofmt_ctx, &pkt);
        ret = av_interleaved_write_frame(ofmt_ctx, &pkt);

        if (ret < 0 && frame_index > 3)
        {
            printf("Error muxing packet\n");
            break;
        }

        av_free_packet(&pkt);
    }

#if USE_H264BSF
    av_bitstream_filter_close(h264bsfc);
#endif
    //Write file trailer
    av_write_trailer(ofmt_ctx);
end:
    avformat_close_input(&ifmt_ctx);
    /* close output */
    if (ofmt_ctx && !(ofmt->flags & AVFMT_NOFILE))
        avio_close(ofmt_ctx->pb);
    avformat_free_context(ofmt_ctx);
    printf("-----finish------\n");
    if (ret < 0 && ret != AVERROR_EOF)
    {
        printf("Error occurred.\n");
        return -1;
    }
    return 0;
}
