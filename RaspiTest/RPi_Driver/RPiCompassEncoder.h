#pragma once
#include "Compass.h"
#include "Odometry.h"
class RPiCompassEncoder : public Compass
{
private:
	Odometry* odometry;

public:
	RPiCompassEncoder(Odometry* odometry);
	double getDirection();
};

