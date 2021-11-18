#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	// ColorDetector cdetect;

	// floodFile函数
	Mat img1 = imread("E:/cvpic/boldt.jpg");
	if (img1.empty()) return;
	// 像素是BGR的格式
	floodFill(img1, Point(100, 50), Scalar(240, 130, 180), (Rect*)(0), Scalar(35, 35, 35), Scalar(35, 35, 35), FLOODFILL_FIXED_RANGE);
	imshow("FloodFile", img1);
	waitKey();
}