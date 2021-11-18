# include <iostream>
# include <opencv2/core.hpp>
# include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void main() {
	Mat rst;
	Mat bgM, fgM;
	Rect rect(5, 70, 260, 120);
	Rect rect1(122, 23, 222, 106);
	Mat img1 = imread("E:/cvpic/boldt.jpg");
	if (img1.empty()) {
		cout << "no picture!\n";
		return;
	}

	grabCut(img1, rst, rect1, bgM, fgM, 5, GC_INIT_WITH_RECT);
	//grabCut(img1, rst, rect, bgM, fgM, 5, GC_INIT_WITH_RECT);
	compare(rst, GC_PR_FGD, rst, CMP_EQ);
	Mat foreground(img1.size(), CV_8UC3, Scalar(255, 255, 255));
	rst = rst & 1;
	img1.copyTo(foreground, rst);
	imshow("img1", img1);
	imshow("foreground", foreground);
	waitKey();
	system("pause");
}