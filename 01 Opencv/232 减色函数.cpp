#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void colorReduce(Mat image, int div = 64)
{
	int n1 = image.rows;
	int nc = image.cols * image.channels();
	for (int j = 0; j < n1; j++) {
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++) {
			data[i] = data[i] / div * div + div / 2;
		}
	}
}

void colorReduce2(Mat image, int div = 64)
{
	int n1 = image.rows;
	int nc = image.cols * image.channels();
	if (image.isContinuous()) {
		nc = nc * n1;
		n1 = 1;
	}
	int n = static_cast<int>(
		log(static_cast<double>(div)) / log(2.0) + 0.5);
	uchar mask = 0xFF << n;
	uchar div2 = div >> 1;
	for (int j = 0; j < n1; j++) {
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++) {
			*data &= mask;
			*data++ += div2;
			//*data++ += div2>>1;
		}
	}
}

// 迭代器扫描图像
void colorReduce3(Mat image, int div = 64)
{
	/*int n1 = image.rows;
	int nc = image.cols * image.channels();
	if (image.isContinuous()) {
		nc = nc * n1;
		n1 = 1;
	}*/
	int n = static_cast<int>(
		log(static_cast<double>(div)) / log(2.0) + 0.5);
	// 用来截取像素值的掩码
	uchar mask = 0xFF << n;
	uchar div2 = div >> 1;
	// 迭代器
	Mat_<Vec3b>::iterator it = image.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = image.end<Vec3b>();
	for (; it != itend; it++) {
		(*it)[0] &= mask;
		(*it)[0] += div2;
		(*it)[1] &= mask;
		(*it)[1] += div2;
		(*it)[2] &= mask;
		(*it)[2] += div2;
	}
	/*for (int j = 0; j < n1; j++) {
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++) {
			*data &= mask;
			*data++ += div2;
		}
	}*/
}

void colorReduce4(Mat& image, int div = 64) {
	Mat lookup(1, 256, CV_8U);
	for (int i = 0; i < 256; i++)
		lookup.at<uchar>(i) = i / div * div + div / 2;
	LUT(image, lookup, image);
}

void main()
{
	Mat img1 = imread("E:/cvpic/boldt.jpg", IMREAD_GRAYSCALE);
	if (img1.empty()) return;
	imshow("img1", img1);

	// 减色函数 2
	
	Mat img2 = imread("E:/cvpic/boldt.jpg", IMREAD_GRAYSCALE);
	if (img2.empty()) return;
	const int64 start2 = getTickCount();
	colorReduce2(img2);
	double duration2 = (getTickCount() - start2) / getTickFrequency();
	cout << "Duration 2 is " << duration2 << " ms" << endl;//num2
	imshow("IMG2", img2);

	// 减色函数 1
	const int64 start1 = getTickCount();
	colorReduce(img1);
	double duration1 = (getTickCount() - start1) / getTickFrequency();
	cout << "Duration 1 is " << duration1 << " ms" << endl;//num1
	imshow("IMG1", img1);

	// 减色函数 3
	
	Mat img3 = imread("E:/cvpic/boldt.jpg"); /*, IMREAD_GRAYSCALE*/ //函数内部有3b应用
	if (img3.empty()) return;
	const int64 start3 = getTickCount();
	colorReduce3(img3);
	double duration3 = (getTickCount() - start3) / getTickFrequency();
	cout << "Duration 3 is " << duration3 << " ms" << endl;//num2
	imshow("IMG3", img3);

	// 减色函数 4

	Mat img4 = imread("E:/cvpic/boldt.jpg"); /*, IMREAD_GRAYSCALE*/ //函数内部有3b应用
	if (img4.empty()) return;
	const int64 start4 = getTickCount();
	colorReduce4(img4);
	double duration4 = (getTickCount() - start4) / getTickFrequency();
	cout << "Duration 4 is " << duration3 << " ms" << endl;//num2
	imshow("IMG4", img4);

	waitKey(0);
	system("pause");
}