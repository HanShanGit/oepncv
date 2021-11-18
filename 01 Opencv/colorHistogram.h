#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class ColorHistogram {
	int histSize[3];
	float hranges[2];
	const float* ranges[3];
	int channels[3];
public:
	ColorHistogram() {
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
		channels[0] = 0;
		channels[1] = 2;
		channels[2] = 2;
	}

	Mat getHistogram(const Mat& image) {
		Mat hist;
		calcHist(&image, 1, channels, Mat(), hist, 3, histSize, ranges);
		return hist;
	}
	SparseMat getSparseHistogram(const Mat&image) {
		SparseMat hist(3, histSize, CV_32F);
		calcHist(&image, 1, channels, Mat(), hist, 3, histSize, ranges);
		return hist;
	}

	void setSize(int size) {
		histSize[0] = histSize[1] = histSize[2] = size;
	}

	Mat getHueHistogram(const Mat& image, int minSat = 0) {
		Mat hist;
		Mat hsv;
		cvtColor(image, hsv, CV_BGR2HSV);
		Mat mask;
		if (minSat > 0) {
			vector<Mat> v;
			split(hsv, v);
			threshold(v[1], mask, minSat, 255, THRESH_BINARY);
		}
		hranges[0] = 0.0;
		hranges[1] = 180.0;
		channels[0] = 0;
		calcHist(&hsv, 1, channels, mask, hist, 1, histSize, ranges);
		return hist;
	}
};