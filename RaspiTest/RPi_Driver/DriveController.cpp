#include "DriveController.h"

DriveController::DriveController() {

	wiringPiSetupGpio();

	for (int i = 0; i < 4; i++) {
		softPwmCreate(_Motor_BCM[i], 0, 100);
	}
	pinMode(_Encoder_BCM[0], INPUT);
	pinMode(_Encoder_BCM[1], INPUT);

	_motor_l   = new RPiMotor(_Motor_BCM[0], _Motor_BCM[1]);
	_motor_r   = new RPiMotor(_Motor_BCM[2], _Motor_BCM[3]);
	_encoder_l = new RPiEncoder(23);
	_encoder_r = new RPiEncoder(22);
	_odometry  = new Odometry(_encoder_l, _encoder_r);
	_diffDrive = new DifferentialDrive(_motor_l, _motor_r);

	int i2cCompass = wiringPiI2CSetup(0x60);
	if (wiringPiI2CReadReg8(i2cCompass, 1) != -1) {
		_compass = new RPiCompassI2C(i2cCompass);
	}
	else {
		_compass = new RPiCompassEncoder(_odometry);
	}
}

void DriveController::moveForward() {
	_odometry->reset();
	_diffDrive->moveForward();
}
void DriveController::moveForward(int distance) {
	_diffDrive->moveForward();
	_odometry->reset();
	while (_odometry->getDistance() < distance) {
	}
	_diffDrive->stop();
}
void DriveController::moveLeft() {

}

void DriveController::moveLeft(double angle) {

}

void DriveController::moveRight() {

}

void DriveController::moveRight(double angle) {

}

void DriveController::turnLeft() {
	_diffDrive->turnLeft();
}

void DriveController::turnLeft(double angle) {

	double startAngle = _compass->getDirection();
	double currentAngle = 0;
	double target = (int)(startAngle - angle + 360) % 360;
	double backBoundary = (int)(startAngle + 10 + 360) % 360;


	_diffDrive->turnLeft();

	do {
		double currentAngle = _compass->getDirection();
	} while (currentAngle > target || currentAngle < backBoundary);

	_diffDrive->stop();
}

void DriveController::turnRight() {
	_diffDrive->turnRight();
}

void DriveController::turnRight(double angle) {

	double startAngle = _compass->getDirection();
	double currentAngle = 0;
	double target = (int)(startAngle + angle + 360) % 360;
	double backBoundary = (int)(startAngle - 10 + 360) % 360;


	_diffDrive->turnRight();

	do {
		double currentAngle = _compass->getDirection();
	} while (currentAngle < target || currentAngle > backBoundary);

	_diffDrive->stop();
}

void DriveController::stop() {
	_diffDrive->stop();
}
