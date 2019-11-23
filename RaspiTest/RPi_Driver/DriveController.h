#pragma once
#include <wiringPi.h>
#include "RPiMotor.h"
#include "RPiEncoder.h"
#include "Odometry.h"
#include "DifferentialDrive.h"
#include "Compass.h"
#include "RPiCompassEncoder.h"
#include "RPiCompassI2C.h"
#include <thread>
#include <chrono>
#include <math.h>
#include <stdio.h>

using namespace std;

class DriveController
{

private:
	const int _Motor_BCM[4] = { 19, 20, 21,26 };
	const int _Encoder_BCM[2] = { 22, 23 };

	RPiMotor* _motor_l;
	RPiMotor* _motor_r;
	RPiEncoder* _encoder_l;
	RPiEncoder* _encoder_r;
	Odometry* _odometry;
	DifferentialDrive* _diffDrive;
	Compass* _compass;

public:
	DriveController();
	void moveForward();
	void moveForward(int distance);
	void moveLeft();
	void moveLeft(double angle);
	void moveRight();
	void moveRight(double angle);
	void turnLeft();
	void turnLeft(double angle);
	void turnRight();
	void turnRight(double angle);
	void stop();
};

