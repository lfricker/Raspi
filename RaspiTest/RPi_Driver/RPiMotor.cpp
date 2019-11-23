#include "RPiMotor.h"


RPiMotor::RPiMotor(int BCM_pin1, int BCM_pin2) {
	this->BCM_pin1 = BCM_pin1;
	this->BCM_pin2 = BCM_pin2;
	this->power = 0;
}

void RPiMotor::setPower(double power) {
	if (power < 0) {
		this->power = 0;
	}
	else if (power > 100) {
		this->power = 100;
	} else {
		this->power = power;
	}

	softPwmWrite(this->BCM_pin1, (int)this->power);
	softPwmWrite(this->BCM_pin2, 0);
}

double RPiMotor::getPower() {
	return this->power;
}
