#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class WatershedSegmenter {
	Mat markers;
public:
	void setMarkers(const Mat& markerImage) {
		markerImage.convertTo(markers, CV_32S);
	}

	Mat process(const Mat& image) {
		watershed(image, markers);
		return markers;
	}

	Mat getSegmentation() { // method 1
		Mat tmp;
		markers.convertTo(tmp, CV_8U);
		return tmp;
	}

	Mat getWatersheds() { // method 2
		Mat tmp;
		markers.convertTo(tmp, CV_8U, 255, 255);
		return tmp;
	}
};