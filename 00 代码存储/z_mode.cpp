#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main() {
	Mat img1 = imread("E:/cvpic/boldt.jpg", 0);
	if (img1.empty()) {
		cout << "NOPICTURE!\n";
		return;
	}


	waitKey(0);
	system("pause");
}