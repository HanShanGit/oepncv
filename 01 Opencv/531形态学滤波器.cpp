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
	imshow("initial", image);

	Mat closed;
	Mat element(5, 5, CV_8U, Scalar(1));
	morphologyEx(image, closed, MORPH_CLOSE, element);
	imshow("closed", closed);

	Mat opened;
	morphologyEx(image, opened, MORPH_OPEN, element);
	imshow("opened", opened);

	Mat result; // ¿ªÆôÂË²¨Æ÷¡¾ÏÈ¸¯Ê´ºóÅòÕÍ¡¿
	erode(image, result, Mat());
	dilate(image, result, Mat());
	imshow("erode and dilate", result);	// { Í¼Ïñ²î±ð¹ý´ó }

	waitKey(0);
	system("pause");
}