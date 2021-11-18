#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void main()
{
	Mat image;
	std::cout << "This image is " << image.rows << " x " << image.cols << std::endl;
	image = imread("E:\\cvPic\\puppy.bmp");
	if (image.empty())
	{
		std::cout << "图片未找到" << std::endl;	//std:: 使用标准命名空间
		return ;
	}
	//cout << "image.row=" << image.rows << " , image.col=" << image.cols << " , image.channel=" << image.channels() << endl;

	//显示原图像
	namedWindow("Original");
	imshow("Original", image);

	//反转图像
	Mat result;
	flip(image, result, 1);
	//namedWindow("Out put");
	imshow("Out put", result);

	//保存反转图像
	imwrite("output.bmp", result);

	//将图像转为灰度图
	Mat image2;
	image2 = imread("E:\\cvPic\\puppy.bmp", IMREAD_GRAYSCALE);
	if (image2.empty())
	{
		std::cout << "图片未找到" << std::endl;	//std:: 使用标准命名空间
		return;
	}
	//namedWindow("gray");
	imshow("gray", image2);

	//将图像转为三通道图像
	Mat image3 = imread("E:\\cvPic\\puppy.bmp", IMREAD_COLOR);
	if (image3.empty()) return;
	imshow("santongdao", image3);

	waitKey(0);
	std::cout << "This image is " << image.rows << " x " << image.cols << std::endl;
	system("pause");
}