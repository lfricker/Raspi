#pragma once
#include "Motor.h"
class SimMotor : public Motor
{
private:
	double power;

public : 
	SimMotor();
	double getPower();
	void setPower(double power);
};

