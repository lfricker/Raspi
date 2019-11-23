#pragma once
#include "DriveController.h"
#include "ObjectFinder.h"

class ObjectFollower
{
private:
	DriveController* _driveController;
	ObjectFinder* _objFinder;

public:
	ObjectFollower(int lowH, int highH, int lowS, int highS, int lowV, int highV);
	void goHunting();
};

