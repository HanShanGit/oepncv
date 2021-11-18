#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
#include <iostream>
#include "Histogram1D.h"
using namespace cv;
using namespace std;



void main() {
	Mat image = imread("E:/cvpic/lena.jpg", 0);// 0表示以黑白方式打开
	Mat image2 = imread("E:/cvpic/group.jpg", 0);// 0表示以黑白方式打开
	if (image.empty()||image2.empty()) {
		cout << "no picture!\n";
		return;
	}
	Histogram1D h;
	Mat hist0 = h.getHistogram(image);
	/*for (int i = 0; i < 256; i++) {
		cout << "value: " << i << " = " << hist0.at<float>(i) << endl;
	}*/
	//namedWindow("HISTOGRAM");
	Mat img = imread("E:/cvpic/lena.jpg");
	if (img.empty()) {
		cout << "no picture!\n";
		return;
	}
	//image.copyTo(img);
	imshow("normal", img);
	imshow("histogram", h.getHistogramImage(img));
	Mat thresholded;
	threshold(img, thresholded, 70, 255, THRESH_BINARY);
	imshow("threshold", thresholded);
	//Mat tem(1, 256, CV_8U);
	//Mat inversRresult = h.applyLookUp(img, tem);
	//imshow("inverseResult", inversRresult);
	//Mat indexResult;
	//equalizeHist(img, indexResult);
	//imshow("indexRestlt", indexResult);
	//imshow("histogram_jun", h.getHistogramImage_jun(image));
	Mat lookup(1, 256, CV_8U);
	Mat negativeIMG = h.applyLookUp(image, lookup);

	imshow("negativeIMG", negativeIMG); // 没有反应(P75)
	waitKey(0);
	system("pause");
}