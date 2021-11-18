#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Histogram1D.h"
using namespace cv;
using namespace std;

void convertToBinaryPlanes(const Mat& input, Mat& output, int nPlanes) {
	int n = 8 - static_cast<int>(log(static_cast<double>(nPlanes)) / log(2.0));
	uchar mask = 0xFF << n;
	vector<Mat>planes;
	Mat reduced = input & mask;
	for (int i = 0; i < nPlanes; i++) {
		planes.push_back((reduced == (i << n)) & 0x1);
	}
	merge(planes, output);
}

template<typename T,int N>
class IntegralImage {
	Mat intergralImage;
public:
	IntegralImage(Mat image) {
		intergral(image, intergralImage, DataType<T>type);
	}
	Vec<T, N> operator()(int x0, int y0, int widht, int height) {
		return (integralImage.at<Vec<T, N>>(y0 + height, x0 + width) -
			integralImage.at<Vec<T, N>>(y0 + height, x0) -
			integralImage.at<Vec<T, N>>(y0, x0 + width) +
			integralImage.at<Vec<T, N>>(y0, x0));
	}
};

void main() {
	Mat image = imread("bike55.bmp", 0);
	int x0 = 97, y0 = 112;
	int width = 25, height = 30;
	Mat roi(image, Rect(x0, y0, width, height));
	Scalar SUM = sum(roi);
	Mat intergralImage;
	integral(image, intergralImage, CV_32S);

	Histogram1D h;
	h.setNBins(16);
	Mat refHistogram = h.getHistogram(roi);
	Mat planes;
	Mat secondImage = imread("bike65.bmp", 0);
	convertToBinaryPlanes(secondImage, planes, 16);
	IntegralImage<float, 16> intHistogram(planes);
	double maxSimilarity = 0.0;
	int xbest, ybest;
	for (int y = 110; y < 120; y++) {
		for (int x = 0; x < secondImage.cols - width; x++) {
			histogram = intHistogram(x, y, width, height);
			double distance = compareHist(refHistogram, histogram, CV_COMP_INTERSECT);
			if (distance > maxSimilarity) {
				xbest = x;
				ybest = y;
				maxSimilarity = distance;
			}
		}
	}
	rectangle(secondImage, Rect(xbest, ybest, width, height), 0);
	imshow("result", secondImage);
	waitKey(0);
}