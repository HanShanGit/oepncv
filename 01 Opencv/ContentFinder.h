#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std; 

class ContentFinder {
	float hranges[2];
	const float* ranges[3];
	int channels[3];
	float thresholded;
	Mat histogram;
public:
	ContentFinder() :thresholded(0.1f) {
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
	}

	void setHistogram(const Mat& h) {
		histogram = h;
		normalize(histogram, histogram, 1.0);
	}

	void setThreshold(float th) {
		thresholded = th;
	}

	Mat find(const Mat& image) {
		Mat result;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;
		return find(image, hranges[0], hranges[1], channels);
	}

	Mat find(const Mat& image, float minValue, float maxValue, int* channels) {
		Mat result;
		hranges[0] = minValue;
		hranges[1] = maxValue;
		for (int i = 0; i < histogram.dims; i++)
			this->channels[i] = channels[i];
		calcBackProject(&image, 1, channels, histogram, result, ranges, 255.0);
		if (thresholded > 0.0)
			threshold(result, result, 255.0 * thresholded, 255.0, THRESH_BINARY);
		return result;
		/*
		cv::Mat result;

		hranges[0] = minValue;
		hranges[1] = maxValue;

		if (isSparse) { // call the right function based on histogram type
			for (int i = 0; i < histogram.dims(); i++)
				this->channels[i] = channels[i];
			cv::calcBackProject(&image,
				1,            // we only use one image at a time
				channels,     // vector specifying what histogram dimensions belong to what image channels
				histogram,   // the histogram we are using
				result,       // the resulting back projection image
				ranges,       // the range of values, for each dimension
				255.0         // the scaling factor is chosen such that a histogram value of 1 maps to 255
			);
		}
		else {
			for (int i = 0; i < histogram.dims; i++)
				this->channels[i] = channels[i];
			cv::calcBackProject(&image,
				1,            // we only use one image at a time
				channels,     // vector specifying what histogram dimensions belong to what image channels
				histogram,    // the histogram we are using
				result,       // the resulting back projection image
				ranges,       // the range of values, for each dimension
				255.0         // the scaling factor is chosen such that a histogram value of 1 maps to 255
			);
		//}
		// Threshold back projection to obtain a binary image
		if (thresholded > 0.0)
			cv::threshold(result, result, 255.0 * thresholded, 255.0, cv::THRESH_BINARY);
		return result;
		*/
	}
};