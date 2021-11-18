#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat img1 = imread("E:/cvpic/tower.jpg", 0);
	if (img1.empty()) {
		cout << "NOPICTURE!\n";
		return;
	}
	imshow("initial", img1);

	Mat imageMask(img1.size(), CV_8U, Scalar(0));
	rectangle(imageMask, Point(5, 5), Point(img1.cols - 5, img1.rows - 5), Scalar(255), 3);
	//Mat result = img1 + imageMask;
	rectangle(imageMask, 
		Point(img1.cols / 2 - 10, img1.rows / 2 - 10),
		Point(img1.cols / 2 + 10, img1.rows / 2 + 10), 
		Scalar(1), 10);

	Mat result = img1 + imageMask; // { 图像中间的黑点没有 }

	imshow("image", result); 

	waitKey(0);
	system("pause");
}