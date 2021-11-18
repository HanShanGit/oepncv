#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "ImageComparator.h"
using namespace cv;
using namespace std;

void main() {
	Mat img0 = imread("E:/cvpic/beach.jpg");
	Mat img1 = imread("E:/cvpic/shift1.png");
	Mat img2 = imread("E:/cvpic/lake.jpg");
	if (img0.empty() || img1.empty() || img2.empty()) {
		cout << "NO PICTURE!\n";
		return;
	}
	imshow("img0", img0);
	imshow("img1", img1);
	imshow("img2", img2);
	ImageComparator c;
	c.setReferenceImage(img0);
	double index01 = c.compare(img1);
	double index02 = c.compare(img2);
	cout << "照片0和1之间的相似度为 " << index01 << endl;
	cout << "照片0和2之间的相似度为 " << index02 << endl;
	waitKey(0);
}