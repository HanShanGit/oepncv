#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

//Mat function() {
//	Mat ima(500, 500, CV_8U, 50);
//	return ima;
//}

cv::Mat function() {

	// create image
	cv::Mat ima(500, 500, CV_8U, 50);
	// return it
	return ima;
}

void main()
{
	Mat im1(250, 320, CV_8U, 100);
	imshow("im1", im1);
	waitKey(0);

	im1.create(200, 200,CV_8U);
	im1 = 200;
	imshow("im1", im1);
	waitKey(0);

	Mat im2(240, 320, CV_8UC3, Scalar(0, 0, 255));
	imshow("im1", im2);
	waitKey(0);

	Mat im3 = imread("E:/cvpic/puppy.bmp");
	if (im3.empty()) return;
	Mat im4(im3);
	im1 = im3;
	im3.copyTo(im2);
	Mat im5 = im3.clone();
	flip(im3, im3, 1);
	imshow("im_3", im3);
	imshow("im_1", im1);
	imshow("im_2", im2);
	imshow("im_4", im4);
	imshow("im_5", im5);
	waitKey(0);
	//Mat gray = function();
	/*cv::Mat gray = function();
	imshow("im1", gray);
	waitKey(0);*/
	im1 = imread("E:/cvpic/pupyy.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	im1.convertTo(im2, CV_32F, 1 / 255.0, 0.0);
	waitKey(0);
	system("pause");
}
