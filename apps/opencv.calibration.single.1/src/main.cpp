#include <iomanip>
#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    // 标定所用图像文件的路径
    ifstream fin("input/calib.conf");
    // 保存标定结果的文件
    ofstream fout("output/calib.out");
    //读取每一幅图像，从中提取出角点，然后对角点进行亚像素精确化
    cout << "开始提取角点" << endl;
    int  imageCount = 0;         /* 图像数量 */
    Size imageSize;              /* 图像的尺寸 */
    Size boardSize = Size(9, 6); /* 标定板上每行、列的角点数 */
    vector<Point2f> imagePoints; /* 缓存每幅图像上检测到的角点 */
    vector<vector<Point2f>> imagePointsSet; /* 保存检测到的所有角点 */
    string                  filename;
    while (getline(fin, filename)) {
        imageCount++;
        Mat input = imread(filename);
        //读入第一张图片时获取图像宽高信息
        if (imageCount == 1) {
            imageSize.width  = input.cols;
            imageSize.height = input.rows;
            cout << "image.width = " << imageSize.width << endl;
            cout << "image.height = " << imageSize.height << endl;
            cout << "################" << endl;
        }

        // 用于观察检验输出
        cout << "imageIndex = " << imageCount << endl;

        // 提取角点
        if (0 == findChessboardCorners(input, boardSize, imagePoints)) {
            cout << "can not find chessboard corners!\n"; //找不到角点
            exit(1);
        } else {
            Mat grayImage;
            cvtColor(input, grayImage, CV_RGB2GRAY);
            /* 亚像素精确化 */
            //对粗提取的角点进行精确化
            find4QuadCornerSubpix(grayImage, imagePoints, Size(11, 11));
            // 输出检验
            cout << "image.point = " << imagePoints.size() << endl;
            //保存亚像素角点
            imagePointsSet.push_back(imagePoints);
            /* 在图像上显示角点位置 */
            //用于在图片中标记角点
            drawChessboardCorners(grayImage, boardSize, imagePoints, true);
            //显示图片
            imshow("Camera Calibration", grayImage);
            //暂停0.5S
            waitKey(500);
        }
        cout << "################" << endl;
    }
    // int imageCount = imagePointsSet.size();
    cout << "image.count = " << imageCount << endl;
    //每张图片上总的角点数
    int cornerNum = boardSize.width * boardSize.height;
    for (int ii = 0; ii < imageCount; ii++) {
        for (int jj = 0; jj < cornerNum; jj++) {
            // 24
            // 是每幅图片的角点个数。此判断语句是为了输出图片号，便于控制台观看
            if (0 == jj % cornerNum) {
                cout << "\n################" << endl;
                cout << "第 " << ii << " 图片的数据: " << endl;
            }
            // 此判断语句，格式化输出，便于控制台查看
            if (0 == jj % 3) {
                cout << endl;
            } else {
                cout.width(25);
            }
            //输出所有的角点
            cout << "(" << imagePointsSet[ii][jj].x << ", "
                 << imagePointsSet[ii][jj].y << ")";
        }
    }

    cout << "\n角点提取完成！\n";

    cout << "开始标定" << endl;
    /* 棋盘三维信息 */
    // 实际测量得到的标定板上每个棋盘格的大小
    Size square_size = Size(10, 10);
    // 保存标定板上角点的三维坐标
    vector<vector<Point3f>> objectPointsSet;
    /* 内参 */
    // 摄像机内参数矩阵
    Mat cameraMatrix = Mat(3, 3, CV_32FC1, Scalar::all(0));
    // 每幅图像中角点的数量
    vector<int> pointCounts;
    // 摄像机的5个畸变系数：k1,k2,p1,p2,k3
    Mat distCoeffs = Mat(1, 5, CV_32FC1, Scalar::all(0));
    /* 外参 */
    // 每幅图像的旋转向量
    vector<Mat> tvecsMat;
    // 每幅图像的平移向量
    vector<Mat> rvecsMat;
    /* 初始化标定板上角点的三维坐标 */
    int i, j, t;
    for (t = 0; t < imageCount; t++) {
        vector<Point3f> tempPoints;
        for (i = 0; i < boardSize.height; i++) {
            for (j = 0; j < boardSize.width; j++) {
                Point3f realPoint;
                /* 假设标定板放在世界坐标系中z=0的平面上 */
                realPoint.x = i * square_size.width;
                realPoint.y = j * square_size.height;
                realPoint.z = 0;
                tempPoints.push_back(realPoint);
            }
        }
        objectPointsSet.push_back(tempPoints);
    }
    /* 初始化每幅图像中的角点数量，假定每幅图像中都可以看到完整的标定板 */
    for (i = 0; i < imageCount; i++) {
        pointCounts.push_back(boardSize.width * boardSize.height);
    }
    /* 开始标定 */
    calibrateCamera(objectPointsSet, imagePointsSet, imageSize, cameraMatrix,
                    distCoeffs, rvecsMat, tvecsMat, 0);
    cout << "标定完成！\n";
    //对标定结果进行评价
    cout << "开始评价标定结果\n";
    double          total_err = 0.0; /* 所有图像的平均误差的总和 */
    double          err       = 0.0; /* 每幅图像的平均误差 */
    vector<Point2f> nImagePoints;    /* 保存重新计算得到的投影点 */
    cout << "\t每幅图像的标定误差：\n";
    fout << "每幅图像的标定误差：\n";
    for (i = 0; i < imageCount; i++) {
        vector<Point3f> tempPoints = objectPointsSet[i];
        // 通过得到的摄像机内外参数，对空间的三维点进行重新投影计算，得到新的投影点
        projectPoints(tempPoints, rvecsMat[i], tvecsMat[i], cameraMatrix,
                      distCoeffs, nImagePoints);
        // 计算新的投影点和旧的投影点之间的误差
        vector<Point2f> tImagePoints = imagePointsSet[i];

        Mat tImagePointsMat = Mat(1, tImagePoints.size(), CV_32FC2);
        Mat nImagePointsMat = Mat(1, nImagePoints.size(), CV_32FC2);
        for (size_t j = 0; j < tImagePoints.size(); j++) {
            nImagePointsMat.at<Vec2f>(0, j) =
                Vec2f(nImagePoints[j].x, nImagePoints[j].y);
            tImagePointsMat.at<Vec2f>(0, j) =
                Vec2f(tImagePoints[j].x, tImagePoints[j].y);
        }
        err = norm(nImagePointsMat, tImagePointsMat, NORM_L2);
        total_err += err /= pointCounts[i];
        std::cout << "第" << i + 1 << "幅图像的平均误差：" << err << "像素"
                  << endl;
        fout << "第" << i + 1 << "幅图像的平均误差：" << err << "像素" << endl;
    }
    std::cout << "总体平均误差：" << total_err / imageCount << "像素" << endl;
    fout << "总体平均误差：" << total_err / imageCount << "像素" << endl
         << endl;
    std::cout << "评价完成！" << endl;
    //保存定标结果
    std::cout << "开始保存定标结果" << endl;
    /* 保存每幅图像的旋转矩阵 */
    Mat rotation_matrix = Mat(3, 3, CV_32FC1, Scalar::all(0));
    fout << "相机内参数矩阵：" << endl;
    fout << cameraMatrix << endl << endl;
    fout << "畸变系数：\n";
    fout << distCoeffs << endl << endl << endl;
    for (int i = 0; i < imageCount; i++) {
        fout << "第" << i + 1 << "幅图像的旋转向量：" << endl;
        fout << tvecsMat[i] << endl;
        // 将旋转向量转换为相对应的旋转矩阵
        Rodrigues(tvecsMat[i], rotation_matrix);
        fout << "第" << i + 1 << "幅图像的旋转矩阵：" << endl;
        fout << rotation_matrix << endl;
        fout << "第" << i + 1 << "幅图像的平移向量：" << endl;
        fout << rvecsMat[i] << endl << endl;
    }
    std::cout << "完成保存" << endl;
    fout << endl;
    system("pause");
    return 1;
}
