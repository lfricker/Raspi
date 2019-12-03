#include "RPiEncoder.h"

RPiEncoder::RPiEncoder(int BCM_pin) {
	this->stopThread = false;
	this->BCM_pin = BCM_pin;
	this->ticks = 0;
	this->current = 0;
	this->previous = 0;
	this->workerThread = std::thread(&RPiEncoder::run, this);
}

RPiEncoder::~RPiEncoder() {
	this->stopThread = true;
	this->workerThread.join();
}

void RPiEncoder::run() {
	while (!this->stopThread) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		this->current = digitalRead(this->BCM_pin);
		if ((0 == this->previous) && (1 == this->current)) {
			this->ticks += 1;
		}
		this->previous = this->current;
	}
}

long RPiEncoder::getTicks() {
	return this->ticks;
}
