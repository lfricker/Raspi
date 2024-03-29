#include "ObjectFollower.h"
#include <iostream>

using namespace std;

ObjectFollower::ObjectFollower(hsvFilter_t filter) {
	_driveController = new DriveController();
	_objFinder = new ObjectFinder(filter);
}

void ObjectFollower::goHunting() {

	cout << "Starting the Hunt" << endl;

	while (1) {

		//Read 5 dummy-pictures to make the object detection more stable
		for (int i = 0; i < 5; ++i) {
			_objFinder->getObjectDirection();
		}

		//adjust the direction according to the object position
		int objDir = _objFinder->getObjectDirection();
		if (objDir < 0) {
			cout << "Target is " << 0 - objDir << " Left" << endl;
			_driveController->turnLeft(0 - objDir);
		}
		else {
			cout << "Target is " << objDir << " Right" << endl;
			_driveController->turnRight(objDir);
		}

		//move towards the object if it has a size (if an object is detected)
		if (_objFinder->getObjectSize()) {
			cout << "Hunting" << endl;
			_driveController->moveForward(100);
		}

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "Returning from Hunt" << endl;
			_driveController->stop();
			break;
		}

	}
}