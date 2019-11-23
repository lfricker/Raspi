//#include <wiringPi.h>
//#include "RPiMotor.h"
//#include "RPiEncoder.h"
//#include "Odometry.h"
//#include "DifferentialDrive.h"
//#include "Compass.h"
//#include "RPiCompassEncoder.h"
//#include "RPiCompassI2C.h"
#include "ObjectFollower.h"
#include <thread>
#include <chrono>
#include <math.h>
#include <stdio.h>

//#include <opencv2/opencv.hpp>
//#include <opencv2/opencv.hpp>
using namespace std;

// USB Dongle 192.168.1.2
// Handy Wlan 192.168.43.100

int main(void)
{
	int lowH;
	int highH;
	int lowS;
	int highS;
	int lowV;
	int highV;

	ObjectFollower objFoll = new ObjectFollower(lowH, highH, lowS, highS, lowV, highV);
	objFoll.goHunting();
	
	return 0;
}