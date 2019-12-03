#pragma once
#include "DriveController.h"
#include "ObjectFinder.h"

class ObjectFollower
{
private:
	DriveController* _driveController;
	ObjectFinder* _objFinder;

public:
	ObjectFollower(hsvFilter_t filter);
	void goHunting();
};

