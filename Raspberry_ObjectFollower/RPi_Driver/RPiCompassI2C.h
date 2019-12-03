#pragma once
#include "Compass.h"
#include <wiringPiI2C.h>
class RPiCompassI2C : public Compass
{
private:
	int I2C_fd_compass;

public:
	RPiCompassI2C(int I2C_fc_compass);
	double getDirection();
};

