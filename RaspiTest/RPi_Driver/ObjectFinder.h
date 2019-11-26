#pragma once

//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>

typedef struct _hsvFilter_ {
	int lowH;
	int highH;
	int lowS;
	int highS;
	int lowV;
	int highV;
} hsvFilter_t;

using namespace cv;

class ObjectFinder
{
private:
	bool _running;
	hsvFilter_t _filter;
	int _objSize;
	const int _maxDegree = 45;

	VideoCapture* _cap;

public:
	ObjectFinder(hsvFilter_t filter);
	int getObjectDirection();
	int getObjectSize();
	~ObjectFinder();
};

