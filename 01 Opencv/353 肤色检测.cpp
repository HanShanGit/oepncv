# include <iostream>
# include <opencv2/core.hpp>
# include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void detectHScolor(Mat&, double, double, double, double, Mat&);

void main() {
	Mat img1 = imread("E:/cvpic/girl.jpg");
	if (img1.empty()) return;
	Mat mask;
	detectHScolor(img1, 160, 10, 25, 166, mask);
	Mat detected(img1.size(), CV_8UC3, Scalar(0, 0, 0));
	imshow("detected01", detected);
	img1.copyTo(detected, mask);
	imshow("img1", img1);
	imshow("detected", detected);
	waitKey();
}

void detectHScolor(Mat& img, double minH, double maxH, double minS, double maxS, Mat& mask) {
	Mat hsv;
	cvtColor(img, hsv, CV_BGR2HSV);
	vector<Mat> channels;
	split(hsv, channels);
	Mat mask1;
	threshold(channels[0], mask1, maxH, 255, THRESH_BINARY_INV);
	Mat mask2;
	threshold(channels[0], mask2, minH, 255, THRESH_BINARY);
	Mat hueMask;
	if (minH < maxH)
		hueMask = mask1 & mask2;
	else
		hueMask = mask1 | mask2;
	Mat satMask;
	inRange(channels[1], minS, maxS, satMask);
	mask = hueMask & satMask;

}