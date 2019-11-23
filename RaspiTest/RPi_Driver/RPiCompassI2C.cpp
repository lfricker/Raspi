#include "RPiCompassI2C.h"
#include <inttypes.h>
#include <stdio.h>

RPiCompassI2C::RPiCompassI2C(int I2C_fd_compass) {
	this->I2C_fd_compass = I2C_fd_compass;
}

double RPiCompassI2C:: getDirection() {
	uint8_t upper_val = (uint8_t)wiringPiI2CReadReg8(this->I2C_fd_compass, 2);
	uint8_t lower_val = (uint8_t)wiringPiI2CReadReg8(this->I2C_fd_compass, 3);
	uint16_t combined_val = 0;
	combined_val = (uint16_t) ((upper_val << 8) | lower_val);
	return (double)(combined_val / 10);
}