/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  仿射变换 测试例子
 *
 *        Version:  1.0
 *        Created:  01/04/19 15:13:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "yudao"<aqnote@aqnote.com>,
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

const char *src_window = "src";
const char *dst_window = "dst";

/**
 * 平移矩阵构造方式 $\left[ \matrix{ 1 & 0 & t_x \\ 0 & 1 & t_y } \right]$
 *
 * 说明：
 * - $t_x$ 表示x方向平移的像素，正为向右移动
 * - $t_y$ 表示y方向平移的象湖，正为向下移动
 *
 * 旋转矩阵构造方式 $$\left[ \matrix{ \alpha & \beta & (1 - \alpha) \cdot
 * center.x - \beta \cdot center.y \\ -\beta & \alpha & \beta \cdot center.x +
 * (1 - \alpha) \cdot center.y} \right]$$
 *
 * 说明：
 * - $\alpha = scale \cdot \cos \theta$
 * - $\beta = scale \cdot \sin \theta$
 * - $\theta$ 为旋转角度：正表示顺时针，负标示逆时针
 * - center标示选择的旋转O点
 *
 */
int main(int, char **argv) {
    namedWindow(src_window, WINDOW_AUTOSIZE);
    namedWindow(dst_window, WINDOW_AUTOSIZE);

    Mat src = imread("input/face_shine_glow.jpg", IMREAD_COLOR);
    imshow(src_window, src);
    waitKey(0);

    Mat dst = Mat::zeros(src.rows, src.cols, src.type());

    // 平移图像，右移动100像素，向下移动50像素
    int array[] = {1, 0, 100, 0, 1, 50};
    Mat translate_mat = Mat(2, 3, CV_32F, array);
    warpAffine(src, dst, translate_mat, src.size());
    imshow(dst_window, dst);
    waitKey(0);

    // 上下翻转
    flip(src, dst, 0);
    imwrite("output/flip0.jpeg", dst);
    imshow(dst_window, dst);
    waitKey(0);

    // 左右翻转
    flip(src, dst, 1);
    imwrite("output/flip1.jpeg", dst);
    imshow(dst_window, dst);
    waitKey(0);

    // 上下翻转+左右翻转
    flip(src, dst, -1);
    imwrite("output/flip-1.jpeg", dst);
    imshow(dst_window, dst);
    waitKey(0);

    // 左右、上下都缩小一倍
    resize(src, dst, Size(src.cols * 0.5, src.rows * 0.5), 0.5, 0.5);
    imshow(dst_window, dst);
    waitKey(0);

    // 左右不变，上下放大一倍数
    resize(src, dst, Size(src.cols * 1, src.rows * 2), 1, 2);
    imshow(dst_window, dst);
    waitKey(0);

    // 仿射变换
    Mat warp_mat(2, 3, CV_32FC1);
    // step1: 构造一个翻转的矩阵
    Point2f srcTri[3];
    srcTri[0] = Point2f(0, 0);
    srcTri[1] = Point2f(src.cols - 1.f, 0);
    srcTri[2] = Point2f(0, src.rows - 1.f);
    Point2f dstTri[3];
    dstTri[0] = Point2f(src.cols * 0.0f, src.rows * 0.33f);
    dstTri[1] = Point2f(src.cols - 1.f, 0);
    dstTri[2] = Point2f(0, (src.rows - 1.f));
    warp_mat = getAffineTransform(srcTri, dstTri);
    cout << "warp_mat:"
         << "\n\t" << warp_mat << endl;
    warpAffine(src, dst, warp_mat, src.size());
    imwrite("output/affine.jpeg", dst);
    imshow(dst_window, dst);
    waitKey(0);

    // 旋转
    Mat rot_mat(2, 3, CV_32FC1);
    // step1: 构造一个以图像中心为原点，旋转pi/2，不缩放的矩阵
    Point center = Point(src.cols / 2, src.rows / 2);
    double angle = -90.0;
    double scale = 1.0;
    rot_mat = getRotationMatrix2D(center, angle, scale);
    cout << "rot_mat:"
         << "\n\t" << rot_mat << endl;
    warpAffine(src, dst, rot_mat, src.size());
    imwrite("output/rotate.jpeg", dst);
    imshow(dst_window, dst);
    waitKey(0);

    return 0;
}
