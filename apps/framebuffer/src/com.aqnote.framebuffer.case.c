/*
 * =====================================================================================
 *
 *       Filename:  com.aqnote.framebuffer.case.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/2018 04:23:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <fcntl.h>

//////////////////////////////////////////////////////////////////////////////
// VARIABLE DEFINE
#define FB_DEVICE "/dev/fb0"

//////////////////////////////////////////////////////////////////////////////
// FUNCTION
int flush_screen(char *buf, char *framebuf, int width, int height);

int com_aqnote_framebuffer_case1_get_display_info()
{
    int fb_fd = 0;
    struct fb_fix_screeninfo fb_fixinfo;
    struct fb_var_screeninfo fb_varinfo;
    if ((fb_fd = open(FB_DEVICE, O_RDWR)) < 0)
    {
        printf("[ERROR] open FrameBuffer device:%s\n", FB_DEVICE);
        return -1;
    }
    else
        printf("[OK] open FrameBuffer device:%s\n", FB_DEVICE);

    if (ioctl(fb_fd, FBIOGET_FSCREENINFO, &fb_fixinfo) == -1)
    {
        printf("[ERROR] FBIOGET_FSCREENINFO\n");
        goto fail;
    }

    printf("ioctl FBIOGET_FSCREENINFO ok\n");
    printf("\tid=%s\n", fb_fixinfo.id);
    printf("\tsmem_start=%#x\n", (unsigned int)fb_fixinfo.smem_start);
    printf("\tmem_len=%d\n", fb_fixinfo.smem_len);
    printf("\ttype=%d\n", fb_fixinfo.type);
    printf("\ttype_aux=%d\n", fb_fixinfo.type_aux);
    printf("\tvisual=%d\n", fb_fixinfo.visual);
    printf("\txpanstep=%d\n", fb_fixinfo.xpanstep);
    printf("\typanstep=%d\n", fb_fixinfo.ypanstep);
    printf("\tywrapstep=%d\n", fb_fixinfo.ywrapstep);
    printf("\tline_length=%d\n", fb_fixinfo.line_length);
    printf("\tmmio_start=%#x\n", (unsigned int)fb_fixinfo.mmio_start);
    printf("\tmmio_len=%#x\n", fb_fixinfo.mmio_len);
    printf("\taccel=%d\n", fb_fixinfo.accel);
    printf("\treserved[0]=%d\n", fb_fixinfo.reserved[0]);
    printf("\treserved[1]=%d\n", fb_fixinfo.reserved[1]);
    printf("\treserved[2]=%d\n", fb_fixinfo.reserved[2]);

    if (ioctl(fb_fd, FBIOGET_VSCREENINFO, &fb_varinfo) == -1)
    {
        printf("[Error] ioctl:FBIOGET_VSCREENINFO\n");
        goto fail;
    }

    printf("ioctl FBIOGET_VSCREENINFO ok\n");
    printf("\txres=%d\n", fb_varinfo.xres);
    printf("\tyres=%d\n", fb_varinfo.yres);
    printf("\txres_virtual=%d\n", fb_varinfo.xres_virtual);
    printf("\tyres_virtual=%d\n", fb_varinfo.yres_virtual);
    printf("\txoffset=%d\n", fb_varinfo.xoffset);
    printf("\tyoffset=%d\n", fb_varinfo.yoffset);
    printf("\tbits_per_pixel=%d\n", fb_varinfo.bits_per_pixel);
    printf("\tgrayscale=%d\n", fb_varinfo.grayscale);
    printf("\tred=%#x\n", fb_varinfo.red);
    printf("\tgreen=%#x\n", fb_varinfo.green);
    printf("\tblue=%#x\n", fb_varinfo.blue);
    printf("\ttransp=%d\n", fb_varinfo.transp);
    printf("\tnonstd=%d\n", fb_varinfo.nonstd);
    printf("\tactivate=%d\n", fb_varinfo.activate);
    printf("\theight=%d\n", fb_varinfo.height);
    printf("\twidth=%d\n", fb_varinfo.width);
    printf("\taccel_flags=%d\n", fb_varinfo.accel_flags);
    printf("\tpixclock=%d\n", fb_varinfo.pixclock);
    printf("\tleft_margin=%d\n", fb_varinfo.left_margin);
    printf("\tright_margin=%d\n", fb_varinfo.right_margin);
    printf("\tupper_margin=%d\n", fb_varinfo.upper_margin);
    printf("\tlower_margin=%d\n", fb_varinfo.lower_margin);
    printf("\thsync_len=%d\n", fb_varinfo.hsync_len);
    printf("\tvsync_len=%d\n", fb_varinfo.vsync_len);
    printf("\tsync=%d\n", fb_varinfo.sync);
    printf("\tvmode=%d\n", fb_varinfo.vmode);
    printf("\trotate=%d\n", fb_varinfo.rotate);
    printf("\treserved[0]=%d\n", fb_varinfo.reserved[0]);
    printf("\treserved[1]=%d\n", fb_varinfo.reserved[1]);
    printf("\treserved[2]=%d\n", fb_varinfo.reserved[2]);
    printf("\treserved[3]=%d\n", fb_varinfo.reserved[3]);
    printf("\treserved[4]=%d\n", fb_varinfo.reserved[4]);

    close(fb_fd);
    return 0;

fail:
    close(fb_fd);
    return -1;
}

int com_aqnote_framebuffer_case2_draw_screen()
{
    int fb_fd = 0;
    struct fb_fix_screeninfo fb_fixinfo;
    struct fb_var_screeninfo fb_varinfo;
    char *fb_addr;
    unsigned long fb_size;
    char *buffer;
    int i = 0;

    if ((fb_fd = open(FB_DEVICE, O_RDWR)) < 0)
    {
        printf("open framebuffer device failed.\n");
        return -1;
    }

    printf("open framebuffer device ok\n");

    if (ioctl(fb_fd, FBIOGET_FSCREENINFO, &fb_fixinfo) == -1)
    {
        printf("ioctl FBIOGET_FSCREENINFO failed.\n");
        return -1;
    }

    printf("ioctl FBIOGET_FSCREENINFO ok\n");

    if (ioctl(fb_fd, FBIOGET_VSCREENINFO, &fb_varinfo) == -1)
    {
        printf("ioctl FBIOGET_VSCREENINFO failed.\n");
        return -1;
    }

    printf("ioctl FBIOGET_VSCREENINFO ok\n");
    // 整个framebuffer的大小
    fb_size = fb_varinfo.yres * fb_fixinfo.line_length;
    // 将framebuffer的物理地址映射到进程地址空间
    fb_addr = (char *)mmap(NULL, fb_size, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, 0);
    // 申请一个缓冲区，采用双缓冲方式
    buffer = (char *)malloc(fb_varinfo.yres * fb_fixinfo.line_length);

    for (i = 0; i <= 0xff; i += 0x0f)
    {
        memset(buffer, i, fb_varinfo.yres * fb_fixinfo.line_length);
        flush_screen(buffer, fb_addr, fb_varinfo.xres, fb_varinfo.yres);
        usleep(1000);
    }

    if (!fb_addr)
        exit(1);

    free(buffer);

    return 0;
}

int flush_screen(char *buf, char *framebuf, int width, int height)
{
    char *t_data = buf;
    char *t_fb_addr = framebuf;
    int bytew = width << 1;
    while (--height >= 0)
    {
        memcpy(t_fb_addr, t_data, bytew);
        t_fb_addr += width;
        t_data += width;
    }
}

int com_aqnote_framebuffer_case2_draw_2()
{
    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0;
    long int location = 0;

    /* Open the file for reading and writing */
    fbfd = open(FB_DEVICE, O_RDWR);
    if (!fbfd)
    {
        printf("[Error] cannot open framebuffer device.\n");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    /* Get fixed screen information */
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo))
    {
        printf("Error reading fixed information.\n");
        exit(2);
    }

    /* Get variable screen information */
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo))
    {
        printf("Error reading variable information.\n");
        exit(3);
    }

    /* Figure out the size of the screen in bytes */
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    /* Map the device to memory */
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)*fbp == -1)
    {
        printf("Error: failed to map framebuffer device to memory.\n");
        exit(4);
    }

    printf("The framebuffer device was mapped to memory successfully.\n");

    x = 200;
    y = 100; /* Where we are going to put the pixel */

    /* Figure out where in memory to put the pixel */
    location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) + (y + vinfo.yoffset) * finfo.line_length;

    *(fbp + location) = 100;     /* Some blue */
    *(fbp + location + 1) = 15;  /* A little green */
    *(fbp + location + 2) = 200; /* A lot of red */
    *(fbp + location + 3) = 0;   /* No transparency */

    munmap(fbp, screensize);
    close(fbfd);

    getchar();

    return 0;
}