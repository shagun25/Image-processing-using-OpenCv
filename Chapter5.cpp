#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Warp Images //////////////////////

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Mat matrix, imgWarp, imgWarp1;
	float w = 250, h = 350;

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst); 
	warpPerspective(img, imgWarp1, matrix1, Point(w, h));
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}


	Point2f src1[4] = { {64,324},{337,278},{91,634},{404,572} };
	matrix1 = getPerspectiveTransform(src, dst);// transform matrix to get warp
	warpPerspective(img, imgWarp, matrix, Point(w, h));
	for (int i = 0; i < 4; i++)
	{
		circle(img, src1[i], 10, Scalar(255, 0, 0), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	imshow("Image Warp", imgWarp1);
	waitKey(0);

}