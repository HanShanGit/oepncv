#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat img = imread("E:/cvpic/book,jpg", 0);
	int blockSize = 21;
	int thresholded = 10;
	int halfSize = blockSize / 2;
	Mat result;
	adaptiveThreshold(img, result, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSize, thresholded);
	imshow("result", result);
	waitKey(0);
}