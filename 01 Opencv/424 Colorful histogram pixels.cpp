#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class ColorHistogram {
	int histSize[3];
	float hranges[2];
	const float* ranges[3];
	int channels[3];
public:
	ColorHistogram() {
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;
		hranges[1] = 256.0;
		ranges[0] = hranges;
		ranges[1] = hranges;
		ranges[2] = hranges;
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;
	}

	Mat getHistogram(Mat& image) {
		Mat hist;
		calcHist(&image, 1, channels, Mat(), hist, 3, histSize, ranges);
		return hist;
	}
	SparseMat getSparseHistogram(Mat& image) {
		SparseMat hist(3, histSize, CV_32F);
		calcHist(&image, 1, channels, Mat(), hist, 3, histSize, ranges);
		return hist;
	}
};

void main() {
	Mat img = imread("E:/cvpic/lena.jpg");
	if (img.empty()) return;
	ColorHistogram h;
	Mat hist0 = h.getHistogram(img);
	//imshow("hist0", hist0);
	for (int i = 0; i < 256; i++) {
		cout << "value: " << i << " = " << hist0.at<float>(i) << endl;
	}
	SparseMat hist1 = h.getSparseHistogram(img);
	//imshow("hist1", hist1);
	waitKey(0);
}