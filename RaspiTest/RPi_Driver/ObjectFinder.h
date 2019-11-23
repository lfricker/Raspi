#pragma once

//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

class ObjectFinder
{
private:
	bool _running;
	int _lowH;
	int _lowS;
	int _lowV;
	int _highH;
	int _highS;
	int _highV;

	int _objSize;

	const int _maxDegree = 45;

	VideoCapture* _cap;

public:
	ObjectFinder(int lowH, int highH, int lowS, int highS, int lowV, int highV);
	int getObjectDirection();
	int getObjectSize();
	~ObjectFinder();
};

