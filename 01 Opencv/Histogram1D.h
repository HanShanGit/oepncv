#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class Histogram1D {
	int histSize[1];
	float hranges[2];
	const float* ranges[1];
	int channels[1];
public:
	Histogram1D() {
		histSize[0] = 256;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		ranges[0] = hranges;
		channels[0] = 0;
	}

	Mat getHistogram(const Mat& image) {
		Mat hist;
		calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
		return hist;
	}

	Mat getHistogramImage(const Mat& image, int zoom = 1) {
		Mat hist = getHistogram(image);
		return getImageOfHistogram(hist, zoom);
	}

	// 直方图均衡化#
	Mat getHistogramImage_jun(const Mat& image, int zoom = 1) {
		Mat hist = getHistogram(image);
		Mat result;
		equalizeHist(hist, result);
		return getImageOfHistogram(result, zoom);
	}
	// #废弃
	Mat getHistogramImage_super(const Mat& image, int zoom = 1) {
		Mat hist = getHistogram(image);
		float percentile = 0.01;
		float number = image.total() * percentile;
		int imin = 0;
		for (float count = 0.0; imin < 256; imin++) {
			if ((count += hist.at<float>(imin)) >= number)
				break;
		}
		int imax = 255;
		for (float count = 0.0; imax >= 0; imax--) {
			if ((count += hist.at<float>(imax)) >= number)
				break;
		}
		return getImageOfHistogram(hist, zoom);
	}

	static Mat getImageOfHistogram(const Mat& hist, int zoom) {
		double maxVal = 0;
		double minVal = 0;
		minMaxLoc(hist, &minVal, &maxVal, 0, 0);
		int histSize = hist.rows;
		Mat histImg(histSize * zoom, histSize * zoom, CV_8U, Scalar(255));
		int hpt = static_cast<int>(0.9 * histSize);
		for (int h = 0; h < histSize; h++) {
			float binVal = hist.at<float>(h);
			if (binVal > 0) {
				int intensity = static_cast<int>(binVal * hpt / maxVal);
				line(histImg, Point(h * zoom, histSize * zoom),
					Point(h * zoom, (histSize - intensity) * zoom),
					Scalar(0), zoom);
			}
		}
		return histImg;
	}

	static Mat applyLookUp(const Mat& image, const Mat& lookup) {
		Mat result;
		LUT(image, lookup, result);
		return result;
	}

	Mat caclBack(Mat& image,Mat& hist) {
		Mat result;
		calcBackProject(&image, 1, channels, hist, result, ranges, 255.0);
		return result;
	}

	void setNBins(int nbins) {

		histSize[0] = nbins;
	}
};