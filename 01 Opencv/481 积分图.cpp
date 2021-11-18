#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat image = imread("bike55.bmp", 0);
	int x0 = 97, y0 = 112;
	int width = 25, height = 30;
	Mat roi(image, Rect(x0, y0, width, height));
	Scalar SUM = sum(roi);
	Mat intergralImage;
	integral(image, intergralImage, CV_32S);
	imshow("intergaralImage", intergralImage);
	waitKey(0);
}