#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat img1 = imread("E:/cvpic/building.jpg", 0);
	if (img1.empty()) {
		cout << "NOPICTURE!\n";
		return;
	}
	imshow("initial", img1);

	Ptr<MSER> prtMSER = MSER::create(5, 200, 2000);
	//Feature2D j;
	vector<vector<Point>> points;
	vector<Rect>rects;
	prtMSER->detecRegions(img1, points, rects);
	Mat output(img1.size(), CV_8UC3);
	output = Scalar(255, 255, 255);
	RNG rng;
	for (vector<vector<Point>>::reverse_iterator it = points.rbegin(); it != points.rend(); ++it) {
		Vec3b c(rng.uniform(0, 254), rng.uniform(0, 254), rng.uniform(0, 254));
		for (vector<Point>::iterator itPts = it->begin(); itPts != it->end(); ++itPts) {
			output.at<Vec3b>(*itPts) = c;
		}
	}
	imshow("output", output);

	// ªÊ÷∆æÿ–Œ
	Mat img2 = img1.clone();
	vector<Rect>::iterator itr = rects.begin();
	vector < vector<Point>>::iterator itp = points.begin();
	for (; itr != rects.end(); ++itr, ++itp) {
		if (static_cast<double>(itp->size()) / itr->area() > 0.6)
			rectangle(img2, *itr, Scalar(255), 2);
	}
	imshow("recrangle", img2);

	//ªÊ÷∆Õ÷‘≤
	for (vector<vector<Point>>::iterator it = points.begin(); it != points.end(); ++it) {
		for (vector<Point>::iterator itPts = it->begin(); itPts != it->end(); ++it) {
			RotatedRect rr = minAreaRect(*it);
			if (rr.size.height / rr.size.height > 0.6 || rr.size.height / rr.size.height < 1.6)
				ellipse(img2, rr, Scalar(255), 2);
		}
	}
	imshow("ellipse", img2);

	
	waitKey(0);
	system("pause");
}