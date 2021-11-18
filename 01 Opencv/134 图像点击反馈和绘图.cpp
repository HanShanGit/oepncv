#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void onMouse(int, int, int, int, void*);

void main()
{
	Mat im1 = imread("E:/cvpic/puppy.bmp", IMREAD_GRAYSCALE);
	/*if (im1.empty()) return;*/
	if (im1.empty())
	{
		std::cout << "图片未找到" << std::endl;	//std:: 使用标准命名空间
		return;
	}
	// 得到图像的行列,chanel
	cout << "image.row=" << im1.rows << " , image.col=" << im1.cols << " , image.channel=" << im1.channels() << endl;

	// 点击图像获取坐标及像素值
	imshow("pic1", im1);
	setMouseCallback("pic1", onMouse, reinterpret_cast<void*>(&im1));

	// 在图像中标记
	// 函数在opencv2/imgproc.hpp中
	circle(im1, Point(155,110), 50, 0, 2);	
	putText(im1, "This is a dog", Point(40, 200), FONT_HERSHEY_PLAIN, 2.0, 255, 2);
	imshow("pic2", im1);

	// 在im1中插入Logo
	Mat img1 = imread("E:/cvpic/puppy.bmp");
	if (img1.empty()) {
		/*std::*/cout << "图片未找到" << /*std::*/endl;	// std:: 使用标准命名空间
		return;
	}
	Mat logo = imread("E:/cvpic/smalllogo.png");
	if (logo.empty())	{
		/*std::*/cout << "图片未找到" << /*std::*/endl;	// std:: 使用标准命名空间
		return;
	}
	Mat imgROI(img1,Rect(img1.cols - logo.cols, img1.rows - logo.rows, logo.cols, logo.rows));
	Mat mask(logo);
	logo.copyTo(imgROI, mask);
	imshow("logo", img1);
	waitKey(0);
	system("pause");
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat* im = reinterpret_cast<Mat*>(param);
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout<<"at ("<<x<<","<<y<<" ) value is : "<<static_cast<int>
			(im->at<uchar>(Point(x, y))) << endl;
		break;
	}
}