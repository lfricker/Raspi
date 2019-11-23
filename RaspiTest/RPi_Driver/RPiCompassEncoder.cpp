#include "RPiCompassEncoder.h"

RPiCompassEncoder::RPiCompassEncoder(Odometry* odometry) {
	this->odometry = odometry;
}

double RPiCompassEncoder::getDirection() {
	return this->odometry->getHeading();
}
