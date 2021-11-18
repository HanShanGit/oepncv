#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "colorHistogram.h"
#include "ContentFinder.h"
#include <opencv2/video/tracking.hpp>
using namespace std;
using namespace cv;

void main() {
	Mat image = imread("E:/cvpic/baboon01.jpg");
	Mat image2 = imread("E:/cvpic/baboon02.jpg");
	if (image.empty() || image2.empty()) {
		cout << "NO PICTURE!\n";
		return;
	}
	imshow("babbon01", image);
	Rect rect(110, 45, 35, 45);
	Mat imageROI = image(rect);
	int minSat = 65;
	ColorHistogram hc;
	Mat colorhist = hc.getHueHistogram(imageROI, minSat);
	ContentFinder finder;
	finder.setHistogram(colorhist);
	Mat hsv;
	cvtColor(image2, hsv, CV_BGR2HSV);
	int ch[1] = { 0 };
	finder.setThreshold(-1.0f);
	Mat result = finder.find(hsv, 0.0f, 180.0f, ch);
	Rect rect2(110, 260, 35, 40);
	TermCriteria criteria(TermCriteria::MAX_ITER | TermCriteria::EPS, 10, 1);
	meanShift(result, rect2, criteria); // in tracking.hpp 
	imshow("meanshift", result);
	waitKey(0);
}