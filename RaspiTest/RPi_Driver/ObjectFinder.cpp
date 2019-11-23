#include "ObjectFinder.h"
#pragma once

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

ObjectFinder::ObjectFinder(int lowH, int highH, int lowS, int highS, int lowV, int highV) {

	_lowH = lowH;
	_lowS = lowS;
	_lowV = lowV;
	_highH = highH;
	_highS = highS;
	_highV = highV;

	 _cap = new VideoCapture(0); 

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

		inRange(imgHSV, Scalar(_lowH, _lowS, _lowV), Scalar(_highH, _highS, _highV), imgThresholded); //Threshold the image

		//morphological opening (removes small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (removes small holes from the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

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

}
