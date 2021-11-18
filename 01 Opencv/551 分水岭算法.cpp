#include "watershedSegmenter.h"

void main() {
	Mat img1 = imread("E:/cvpic/binary.bmp");
	if (img1.empty()) {
		cout << "NOPICTURE!\n";
		return;
	}

	Mat fg;
	erode(img1, fg, Mat(), Point(-1, 1), 4);
	Mat bg;
	dilate(img1, bg, Mat(), Point(-1, -1), 4);
	threshold(bg, bg, 1, 128, THRESH_BINARY_INV);
	Mat markers(img1.size(), CV_8U, Scalar(0)); // 作为分水岭的输入图像
	markers = fg + bg;
	
	WatershedSegmenter segmenter;
	segmenter.setMarkers(markers);
	Mat result = segmenter.process(markers); // { 函数有问题 }

	imshow("segmentation", markers);
	imshow("watersheds", result);
	waitKey(0);
	system("pause");
}