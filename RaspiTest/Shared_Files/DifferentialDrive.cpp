#include "DifferentialDrive.h"


DifferentialDrive::DifferentialDrive(Motor* motor_left, Motor* motor_right) {
	this->motor_left = motor_left;
	this->motor_right = motor_right;
}

void DifferentialDrive::moveForward() {
	motor_left->setPower(90);
	motor_right->setPower(90);
}

void DifferentialDrive::stop() {
	motor_left->setPower(0);
	motor_right->setPower(0);
}

void DifferentialDrive::turnLeft() {
	motor_left->setPower(80);
	motor_right->setPower(0);
}

void DifferentialDrive::turnRight() {
	motor_left->setPower(0);
	motor_right->setPower(80);
}
