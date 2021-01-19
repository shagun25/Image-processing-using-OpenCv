#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Resize and Crop //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop;

	//cout << img.size() << endl;
	resize(img, imgResize, Size(), 0.5, 0.5); //scale

	Rect roi(200, 100, 300, 300); //roi(Point1,Point2,Width,Height)
	imgCrop = img(roi);  //roi stands for Region of Interest.

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}

