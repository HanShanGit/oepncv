#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Histogram1D.h"
using namespace cv;
using namespace std;

void main() {
	Mat img = imread("E:/cvpic/lena.jpg",0);
	if (img.empty()) {
		cout << "No picture!\n";
		return;
	}
	imshow("lena", img);
	Mat result;
	equalizeHist(img, result);
	imshow("ֱ��ͼ���⻯", result);
	Histogram1D h;
	Mat hist = h.getHistogramImage(result);
	imshow("���⻯ֱ��ͼ", hist);
	waitKey(0);

}