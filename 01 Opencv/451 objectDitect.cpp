#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Histogram1D.h"

using namespace cv;
using namespace std;

void main() {
	Mat img = imread("E:/cvpic/waves.jpg", 0);
	Mat img2 = imread("E:/cvpic/lena.jpg", 0);
	if (img.empty()) {
		cout << "NO PICTURE!:\n";
		return;
	}
	Mat imageROI;
	Mat imageROI2;
	imageROI = img(Rect(216, 33, 24, 30));
	imageROI2 = img2(Rect(77, 22, 50, 50));
	Histogram1D h;
	Mat hist = h.getHistogram(imageROI2);
	normalize(hist, hist, 1.0);
	Mat result = h.caclBack(img2, hist);
	Mat result2;
	bitwise_not(result, result2);// 颜色反转
	imshow("Backprojection result", result2);
	Mat thresholded;
	threshold(result2, thresholded, 200, 255, THRESH_BINARY); // 效果不明显[阈值小了]
	imshow("Detection REsult", thresholded);
	waitKey(0);
	//
}