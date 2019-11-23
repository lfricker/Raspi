#include "Odometry.h"
#include <iostream>

using namespace std;

Odometry::Odometry(Encoder* encoder_left, Encoder* encoder_right) {
	this->encoder_left = encoder_left;
	this->encoder_right = encoder_right;
	mem_left_ticks = 0;
	mem_right_ticks = 0;
}

double Odometry::getDistance() {
	double distance = ((encoder_left->getTicks() - mem_left_ticks) + (encoder_right->getTicks() - mem_right_ticks)) / 2 * mm_per_tick;
	cout << distance << endl;
	return distance;
}

double Odometry::getHeading() {
	return ticks_to_angle((encoder_left->getTicks() - mem_left_ticks) - (encoder_right->getTicks() - mem_right_ticks));  // returns positive angle for right turn and negative for left turn
}

double Odometry::ticks_to_angle(long ticks) {
	return (int)(ticks * degree_per_tick)%360; 
}

void Odometry::reset() {
	mem_left_ticks = encoder_left->getTicks();
	mem_right_ticks = encoder_right->getTicks();
}
