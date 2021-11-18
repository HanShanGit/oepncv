#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
//#include <math>
//#include <opencv2/imgproc.hpp>
#include <random>

using namespace std;
using namespace cv;

void salt(Mat image, int n) {
	default_random_engine generator;
	uniform_int_distribution<int>
		randomRow(0, image.rows - 1);
	uniform_int_distribution<int>
		randomCol(0, image.cols - 1);
	
	int i, j;
	for (int k = 0; k < n; k++) {
		i = randomCol(generator);
		j = randomRow(generator);
		if (image.type() == CV_8UC1) {
			image.at<uchar>(j, i) = 255;
		}
		else if (image.type() == CV_8UC3) {
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}

void main()
{
	Mat img1 = imread("E:/cvpic/boldt.jpg", 1);
	if (img1.empty()) {
		cout << "Í¼Æ¬¶ÁÈ¡Ê§°Ü£¡" << endl;
		return;
	}
	cout << img1.rows << " " << img1.cols << endl;
	salt(img1, 3000);
	//namedWindow("im1g1");
	imshow("img1", img1);
	imshow("img2", img1);
	waitKey(0);
	system("pause");
}