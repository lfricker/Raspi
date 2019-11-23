#include "DifferentialDrive.h"


DifferentialDrive::DifferentialDrive(Motor* motor_left, Motor* motor_right) {
	this->motor_left = motor_left;
	this->motor_right = motor_right;
}

void DifferentialDrive::moveForward() {
	this->motor_left->setPower(100);
	this->motor_right->setPower(100);
}

void DifferentialDrive::stop() {
	this->motor_left->setPower(0);
	this->motor_right->setPower(0);
}

void DifferentialDrive::turnLeft() {
	this->motor_left->setPower(80);
	this->motor_right->setPower(0);
}

void DifferentialDrive::turnRight() {
	motor_left->setPower(0);
	motor_right->setPower(80);
}
