#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat img1 = imread("E:/cvpic/boldt.jpg", 0);
	Mat img2 = imread("E:/cvpic/book.jpg", 0);
	if (img1.empty() || img2.empty()) {
		cout << "NOPICTURE!\n";
		return;
	}

	Mat result;
	morphologyEx(img1, result, MORPH_GRADIENT, Mat());
	bitwise_not(result, result); 
	imshow("Edge image", result);

	Mat result2;
	Mat element(7, 7, CV_8U, Scalar(1));
	morphologyEx(img2, result2, MORPH_BLACKHAT, element);
	bitwise_not(result2, result2);
	imshow("Black Top", result2);
	waitKey(0);
	system("pause");
}