#include "SimMotor.h"


	SimMotor::SimMotor() {
	this->power = 0;
}

void SimMotor::setPower(double power) {
	if (power <= 100 && power >= 0) {
		this->power = power;
	}
	else if (power < 0) {
		this->power = 0;
	}
	else {
		this->power = 100;
	}
}

double SimMotor::getPower() {
	return this->power;
}