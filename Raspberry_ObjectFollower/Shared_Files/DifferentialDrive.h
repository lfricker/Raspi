#pragma once
#include "Motor.h"

class DifferentialDrive
{
private:
	Motor* motor_left;
	Motor* motor_right;

public:
	DifferentialDrive(Motor* motor_left, Motor* motor_right);
	void moveForward();
	void stop();
	void turnLeft();
	void turnRight();
};

