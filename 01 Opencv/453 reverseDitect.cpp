#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "ContentFinder.h"
#include "colorHistogram.h"
using namespace cv;
using namespace std;

void main() {
	ColorHistogram hc;
	Mat color = imread("E:/cvpic/waves.jpg");
	Mat color2 = imread("E:/cvpic/waves.jpg", 0);
	Mat color3 = imread("E:/cvpic/lena.jpg", 0);
	if (color.empty() || color2.empty()) {
		cout << "NO PICTURE!\n";
		return;
	}

	Mat imageROI = color(Rect(0, 0, 100, 45));
	hc.setSize(8);
	imshow("imageROI", imageROI);

	Mat shist = hc.getHistogram(imageROI);
	ContentFinder finder;
	finder.setHistogram(shist);
	finder.setThreshold(0.05f);
	Mat result = finder.find(color);
	imshow("Color detection", result); // 没有结果
	waitKey(0);
}