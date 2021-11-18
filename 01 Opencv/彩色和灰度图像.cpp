#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
//#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	// ����һ�Ų�ɫͼƬ����ʾ
	Mat srcImage = imread("E:/cvpic/boldt.jpg", IMREAD_COLOR);
	if (srcImage.empty()) return 0;
	namedWindow("Image", WINDOW_AUTOSIZE);
	imshow("Image", srcImage);

	int nHeight = srcImage.rows;
	int nWidth = srcImage.cols;

	// ����һ�ŻҶ�ͼ����ʾ������ʹ��ͬһ��ͼƬ ֻ��imread���������һ��������һ��  Ч������ͬ��
	Mat grayImage = imread("E:/cvpic/boldt.jpg", IMREAD_GRAYSCALE);

	if (grayImage.empty()) return 0;
	namedWindow("grayImage", WINDOW_AUTOSIZE);
	imshow("grayImage", grayImage);

	// ������Ϣ
	cout << "ͼ��ĸ߶�" << nHeight << endl;;
	cout << "ͼ��Ŀ��" << nWidth << endl;
	cout << "Image��ͨ����" << srcImage.channels() << endl;      // ��ɫͼƬ��ͨ����
	cout << "grayImage��ͨ����" << grayImage.channels() << endl; // �Ҷ�ͼƬ��ͨ����

	for (int i = 0; i < nHeight; i++)
	{
		for (int j = 0; j < nWidth; j++)
		{
			srcImage.at<uchar>(i, j) = 0;
			grayImage.at<uchar>(i, j) = 0;
		}
	}
	namedWindow("��ɫͼƬ������Ӧ��ɫͼƬ", WINDOW_AUTOSIZE);
	imshow("��ɫͼƬ������Ӧ��ɫͼƬ", srcImage);

	namedWindow("�Ҷ�ͼƬ������Ӧ��ɫͼƬ", WINDOW_AUTOSIZE);
	imshow("�Ҷ�ͼƬ������Ӧ��ɫͼƬ", grayImage);

	waitKey(0);
	destroyWindow("Image");
	destroyWindow("grayImage");
	destroyWindow("��ɫͼƬ������Ӧ��ɫͼƬ");
	destroyWindow("�Ҷ�ͼƬ������Ӧ��ɫͼƬ");

	return 0;

}