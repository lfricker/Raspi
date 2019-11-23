#include "ObjectFollower.h"
#include <iostream>

using namespace std;

ObjectFollower::ObjectFollower(int lowH, int highH, int lowS, int highS, int lowV, int highV) {
	_driveController = new DriveController();
	_objFinder = new ObjectFinder(lowH, highH, lowS, highS, lowV, highV);
}

void ObjectFollower::goHunting() {

	cout << "Starting the Hunt" << endl;

	while (1) {
		int objDir = _objFinder->getObjectDirection();
		if (objDir < 0) {
			cout << "Target is " << 0 - objDir << " Left" << endl;
			_driveController->turnLeft(0 - objDir);
		}
		else {
			cout << "Target is " << objDir << " Right" << endl;
			_driveController->turnRight(objDir);
		}

		cout << "Hunting" << endl;
		_driveController->moveForward(100);

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "Returning from Hunt" << endl;
			_driveController->stop();
			break;
		}

	}
}