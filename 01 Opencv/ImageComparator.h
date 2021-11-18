#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "colorhistogram.h"
using namespace cv;
using namespace std;

class ImageComparator {
	Mat refH;
	Mat inputH;
	ColorHistogram hist;
	int nBins;
public:
	ImageComparator() :nBins(8) {
	}
	void setReferenceImage(const Mat& image) {
		hist.setSize(nBins);
		refH = hist.getHistogram(image);
	}
	double compare(const Mat& image) {
		inputH = hist.getHistogram(image);
		return compareHist(refH, inputH, HISTCMP_INTERSECT);
	}
};