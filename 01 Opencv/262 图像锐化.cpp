# include <iostream>
# include <opencv2/core.hpp>
# include <opencv2/highgui.hpp>
# include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void sharpen(const Mat&, Mat&);
void sharpen2D(const Mat&, Mat&);	// 效果要比上面好些


void main() {
	Mat img = imread("E:/cvpic/boldt.jpg");
	Mat imgGray = imread("E:/cvpic/boldt.jpg", IMREAD_GRAYSCALE);
	if (img.empty()) {
		cout << "打开失败！" << endl;
		return;
	}
	Mat rst;
	Mat rstGray;
	imshow("imgGray", imgGray);
	sharpen2D(imgGray, rstGray);
	imshow("rstGray", rstGray);

	imshow("img", img);
	sharpen(img, rst);
	imshow("rst", rst);
	waitKey(0);
	system("pause");
}

void sharpen(const Mat& image, Mat& result) {
	result.create(image.size(), image.type());
	int nchannels = image.channels();
	for (int j = 1; j < image.rows - 1; j++) {
		const uchar* previous = image.ptr<const uchar>(j - 1);
		const uchar* current = image.ptr<const uchar>(j);
		const uchar* next = image.ptr<const uchar>(j + 1);

		uchar* output = result.ptr<uchar>(j);
		for (int i = nchannels; i < (image.cols - 1) * nchannels; i++) {
			// 使用锐化算子
			*output++ = saturate_cast<uchar>(
				5 * current[i] - current[i - nchannels] - current[i + nchannels] - previous[i] - next[i]);
		}
	}
	result.row(0).setTo(Scalar(0));
	result.row(result.rows - 1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols - 1).setTo(Scalar(0));
}

void sharpen2D(const Mat& image, Mat& result) {
	Mat kernel(3, 3, CV_32F, Scalar(0));
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(2, 0) = -1.0;
	// 对图像进行滤波
	filter2D(image, result, image.depth(), kernel);
}