#include "ObjectFinder.h"

using namespace cv;

ObjectFinder::ObjectFinder(hsvFilter_t filter) {

	_filter = filter;

	 _cap = new VideoCapture(1); 

	if (!_cap->isOpened())
	{
		_running = false;
	}
	else {
		_running = true;
	}
}

int ObjectFinder::getObjectDirection() {

	if (_running) {
		Mat imgOriginal;

		bool bSuccess = _cap->read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			return -1;
		}

		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(_filter.lowH, _filter.lowS, _filter.lowV),
			            Scalar(_filter.highH, _filter.highS, _filter.highV), imgThresholded); //Threshold the image


		//Calculate the moments of the thresholded image
		Moments oMoments = moments(imgThresholded);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		int posX = dM10 / dArea;
		_objSize = dArea;
		int width = imgThresholded.cols;

		int objectPosition = ((posX - (width / 2)) * _maxDegree) / (width / 2);

		return objectPosition;
	}
	else {
		_objSize = 0;
		return 0;
	}
}

int ObjectFinder::getObjectSize() {
	return _objSize;
}

ObjectFinder::~ObjectFinder() {
	delete _cap;
}
