#pragma once
#include "Encoder.h"

class Odometry
{
private:
	Encoder* encoder_left;
	Encoder* encoder_right;
	long mem_left_ticks;
	long mem_right_ticks;
	const double mm_per_tick = 207.0 / 20.0;
	const double wheel_distance = 131;
	const double PI = 3.141592654;
	// Umfang = 2*r*pi = 823mm :: Umfang / mm_per_tick = 79.52 tick :: 360° / 79.52 tick = 4.53°/tick
	const double degree_per_tick = 360 / ((2 * wheel_distance * PI) / mm_per_tick);

public:
	Odometry(Encoder* encoder_left, Encoder* encoder_right);
	double getDistance();
	double getHeading();
	double ticks_to_angle(long ticks);
	void reset();
};

