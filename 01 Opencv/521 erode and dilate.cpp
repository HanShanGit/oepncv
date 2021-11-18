#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat image = imread("E:/cvpic/binary.bmp");
	if (image.empty()) {
		cout << "NO PICTURE!\n";
		return;
	}
	Mat eroded;
	erode(image, eroded, Mat());
	Mat eroded3;
	erode(image, eroded3, Mat(), Point(-1, -1), 3);

	Mat dilated;
	dilate(image, dilated, Mat());

	Mat ele;
	Mat element(7, 7, CV_8U, Scalar(1));
	erode(image, ele, element);


	
	imshow("erode1", eroded);
	imshow("dilate1", dilated);
	imshow("element", ele);
	imshow("erode3", eroded3);
	waitKey(0);
}