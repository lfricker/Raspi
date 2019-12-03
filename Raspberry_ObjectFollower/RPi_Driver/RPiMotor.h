#pragma once
#include "Motor.h"
#include <wiringPi.h>
#include <softPwm.h>
class RPiMotor : public Motor
{
private:
	int BCM_pin1;
	int BCM_pin2;
	double power;

public:
	RPiMotor(int BCM_pin1, int BCM_pin2);
	void setPower(double power);
	double getPower();
};

