/*
* First C++ Test
*
*created by Luka Fricker
*date 06.10.2019
*
*/

#include<stdio.h>
#include"SimMotor.h"
#include"SimEncoder.h"
#include"DifferentialDrive.h"
#include"Odometry.h"

using namespace std;

void testEncoder(SimMotor* motor, SimEncoder* encoder); 

void testOdometry(DifferentialDrive* differentialDrive, Odometry* odometry);


int main(int argc, char** args) {

	SimMotor* motor_l = new SimMotor();
	SimEncoder* encoder_l = new SimEncoder(motor_l);
	SimMotor* motor_r = new SimMotor();
	SimEncoder* encoder_r = new SimEncoder(motor_r);
	Odometry* odometry = new Odometry(encoder_l, encoder_r);
	DifferentialDrive* diffDrive = new DifferentialDrive(motor_l, motor_r);

//	testEncoder(motor_l, encoder_l);
	testOdometry(diffDrive, odometry);

	delete diffDrive;
	delete odometry;
	delete encoder_l;
	delete encoder_r;
	delete motor_l;
	delete motor_r;

	return 0;
}

void testEncoder(SimMotor* motor, SimEncoder* encoder) {
	// Zähler von 1 bis 30
	// this_thread::sleep_for 100 Millisekunden
	// Konsolenausgabe der verstrichenen Zeit in Millisekunden und des Zählerstandes des Encoders
	// Wenn der Zählerstand == 10, dann soll die Power des Motors auf 50 gesetzt werden
	// Wenn der Zählerstand == 20, dann soll die Power des Motors auf 100 gesetzt werden

	int counter = 0;
	int sim_step = 100; //Simulation timesteps in ms;

	while (counter < 30) {

		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // hält die Simulaton für 100mS an
		counter += 1;
		if (counter == 10) {
			motor->setPower(50);
		}
		else if (counter == 20) {
			motor->setPower(100);
		}

		printf("Sim_Time: %6d mS, Enc_Count: %6d\n", (counter * sim_step), encoder->getTicks());
	}
}

void testOdometry(DifferentialDrive* differentialDrive, Odometry* odometry) {
	// Solange die gefahrene Distanz < 100mm ist:
	// this_thread::sleep_for 100 Millisekunden
	// Konsolenausgabe des Zählerstandes des Encoders

	differentialDrive->moveForward();

	while (odometry->getDistance() < 100) {
		printf("Current Distance: %3.2lfmm  Orientation: %3.2lfdegree \n", odometry->getDistance(), odometry->getHeading());
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	differentialDrive->turnRight();

	while (odometry->getHeading() < 90) {
		printf("Current Distance: %3.2lfmm  Orientation: %3.2lfdegree \n", odometry->getDistance(), odometry->getHeading());
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	differentialDrive->moveForward();
	odometry->reset();

	while (odometry->getDistance() < 100) {
		printf("Current Distance: %3.2lfmm  Orientation: %3.2lfdegree \n", odometry->getDistance(), odometry->getHeading());
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	differentialDrive->stop();

}