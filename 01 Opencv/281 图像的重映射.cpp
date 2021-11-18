# include <opencv2/core.hpp>
# include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
# include <iostream>

using namespace std;
using namespace cv;

void wave(Mat&, Mat&);

void main() {
	Mat img1 = imread("E:/cvpic/boldt.jpg");
	if (img1.empty()) return;
	Mat rst;
	wave(img1, rst);
	imshow("img1", img1);
	imshow("rst", rst);
	waitKey(0);
}

void wave(Mat& img1, Mat& rst) {
	Mat X(img1.rows, img1.cols, CV_32F);
	Mat Y(img1.rows, img1.cols, CV_32F);
	for (int i = 0; i < img1.rows; i++) {
		for (int j = 0; j < img1.cols; j++) {
			X.at<float>(i, j) = j;
			Y.at<float>(i, j) = i + 5 * sin(j / 10.0);
		}
	}
	remap(img1, rst, X, Y, INTER_LINEAR);
}