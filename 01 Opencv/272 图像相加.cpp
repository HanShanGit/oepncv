# include <iostream>
# include <opencv2/core.hpp>
# include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void main() {
	Mat img1 = imread("E:/cvpic/boldt.jpg");
	Mat img2 = imread("E:/cvpic/rain.jpg");
	if (img1.empty() || img2.empty()) return;
	//imshow("img1", img1);
	//imshow("img2", img2);

	Mat result;
	addWeighted(img1, 0.7, img2, 0.9, 0., result/*, 1*/);
	imshow("addWeighted", result);

	subtract(img1, img2, result);
	imshow("subtract", result);
	
	absdiff(img1, img2, result);
	imshow("absdiff", result);

	result = 0.7 * img1 + 0.9 * img2;
	imshow("жиди", result);

	multiply(img1, img2, result);
	imshow("multiply", result);
	imwrite("multipy.png", result);
	waitKey(0);
	system("pause");
}