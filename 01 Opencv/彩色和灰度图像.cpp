#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
//#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	// 载入一张彩色图片并显示
	Mat srcImage = imread("E:/cvpic/boldt.jpg", IMREAD_COLOR);
	if (srcImage.empty()) return 0;
	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", srcImage);

	int nHeight = srcImage.rows;
	int nWidth = srcImage.cols;

	// 载入一张灰度图并显示，这里使用同一张图片 只是imread函数的最后一个参数不一样  效果是相同的
	Mat grayImage = imread("E:/cvpic/boldt.jpg", IMREAD_GRAYSCALE);

	if (grayImage.empty()) return 0;
	namedWindow("grayImage", WINDOW_AUTOSIZE);
	imshow("grayImage", grayImage);

	// 基本信息
	cout << "图像的高度" << nHeight << endl;;
	cout << "图像的宽度" << nWidth << endl;
	cout << "Image的通道数" << srcImage.channels() << endl;      // 彩色图片的通道数
	cout << "grayImage的通道数" << grayImage.channels() << endl; // 灰度图片的通道数

	for (int i = 0; i < nHeight; i++)
	{
		for (int j = 0; j < nWidth; j++)
		{
			srcImage.at<uchar>(i, j) = 0;
			grayImage.at<uchar>(i, j) = 0;
		}
	}
	namedWindow("彩色图片处理后对应黑色图片", WINDOW_AUTOSIZE);
	imshow("彩色图片处理后对应黑色图片", srcImage);

	namedWindow("灰度图片处理后对应黑色图片", WINDOW_AUTOSIZE);
	imshow("灰度图片处理后对应黑色图片", grayImage);

	waitKey(0);
	destroyWindow("Image");
	destroyWindow("grayImage");
	destroyWindow("彩色图片处理后对应黑色图片");
	destroyWindow("灰度图片处理后对应黑色图片");

	return 0;

}