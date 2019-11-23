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

//#include <opencv2/opencv.hpp>
//#include <opencv2/opencv.hpp>
using namespace std;

// USB Dongle 192.168.1.2
// Handy Wlan 192.168.43.100

void move_forward(DifferentialDrive* drive, Odometry* odometry, double distance);
void turn(DifferentialDrive* drive, Compass* compass, double direction);

int main(void)
{

	const int LEDs_BCM[] = { 4, 17, 27, 5 };
	const int Motor_BCM[] = { 19, 20, 21,26 };
	const int Encoder_BCM[] = { 22, 23 };

	wiringPiSetupGpio();
	for (int i = 0; i < 4; i++) {
		pinMode(LEDs_BCM[i], OUTPUT);
		softPwmCreate(Motor_BCM[i], 0, 100);
	}
	pinMode(Encoder_BCM[0], INPUT);
	pinMode(Encoder_BCM[1], INPUT);


	RPiMotor* motor_l = new RPiMotor(19, 20);
	RPiEncoder* encoder_l = new RPiEncoder(23);
	RPiMotor* motor_r = new RPiMotor(21, 26);
	RPiEncoder* encoder_r = new RPiEncoder(22);
	Odometry* odometry = new Odometry(encoder_l, encoder_r);
	DifferentialDrive* diffDrive = new DifferentialDrive(motor_l, motor_r);

	Compass* compass;
	int I2C_fd_compass = wiringPiI2CSetup(0x60);
	if (wiringPiI2CReadReg8(I2C_fd_compass, 1) != -1) {
		compass = new RPiCompassI2C(I2C_fd_compass);
	}
	else {
		compass = new RPiCompassEncoder(odometry);
	}

	for (int i = 0; i < 2; i += 1) {
		move_forward(diffDrive, odometry, 300);
		turn(diffDrive, compass, 180);
	}
	
	return 0;
}


void move_forward(DifferentialDrive* drive, Odometry* odometry, double distance) {
	// Odometrie reset, Drive “move forward”
	// solange die Distanz nicht erreicht wurde:
	// this_thread::sleep für 1 Millisekunde
	// Drive “stop”

	odometry->reset();
	drive->moveForward();
	odometry->reset();
	while (odometry->getDistance() < distance) {
	}
	drive->stop();
}


void turn(DifferentialDrive* drive, Compass* compass, double direction) {
	// solange die Ausrichtung des Roboters mehr als 3 Grad von „direction“ abweicht:
	// Drive “turn_right” bzw. “turn_left”

	double error = 0;
	double target = (int)(compass->getDirection() + direction) % 360;
	double heading = 0;

	if (direction < 0) {
		drive->turnLeft();
	}
	else if (direction > 0) {
		drive->turnRight();
	}
	
	do {
		
		heading = compass->getDirection();
		error = fabs(heading - target); // funktion schreiben zum Überlauf managen
		this_thread::sleep_for(chrono::milliseconds(2));
	} while (error > 5);

	drive->stop();
}