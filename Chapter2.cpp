#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Basic Functions //////////////////////

void main() {
	try
	{
		string path = "Resources/test.png";
		Mat img = imread(path);  //image imported
		Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
		                                              //functions present in opencv
		cvtColor(img, imgGray, COLOR_BGR2GRAY);

		GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
		Canny(imgBlur, imgCanny, 25, 75);

		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(imgCanny, imgDil, kernel);
		erode(imgDil, imgErode, kernel);
		//Always use kernel for dil,erode as img get structuring element.
		imshow("Image", img);
		imshow("Image Gray", imgGray);
		imshow("Image Blur", imgBlur);
		imshow("Image Canny", imgCanny);
		imshow("Image Dilation", imgDil);
		imshow("Image Erode", imgErode);
		waitKey(0);
	}
	catch (cv::Exception& e)
	{
		cerr << e.msg << endl; // output exception message
	}
}