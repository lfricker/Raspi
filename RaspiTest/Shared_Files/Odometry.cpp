#include "Odometry.h"


Odometry::Odometry(Encoder* encoder_left, Encoder* encoder_right) {
	this->encoder_left = encoder_left;
	this->encoder_right = encoder_right;
	mem_left_ticks = 0;
	mem_right_ticks = 0;
}

double Odometry::getDistance() {
	return ((this->encoder_left->getTicks() - mem_left_ticks) + (this->encoder_right->getTicks() - mem_right_ticks)) / 2 * mm_per_tick;
}

double Odometry::getHeading() {
	return ticks_to_angle((this->encoder_left->getTicks() - mem_left_ticks) - (this->encoder_right->getTicks() - mem_right_ticks));  // returns positive angle for right turn and negative for left turn
}

double Odometry::ticks_to_angle(long ticks) {
	return (int)(ticks * degree_per_tick)%360; 
}

void Odometry::reset() {
	mem_left_ticks = this->encoder_left->getTicks();
	mem_right_ticks = this->encoder_right->getTicks();
}
