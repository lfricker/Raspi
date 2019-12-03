#include "SimEncoder.h"

using namespace std;

SimEncoder::SimEncoder(SimMotor* motor) {
	this->motor = motor;
	this->ticks = 0;
	this->stop_thread = false;
	this->worker_thread = thread(&SimEncoder::run, this);
}

SimEncoder::~SimEncoder() {
	this->stop_thread = true;
	this->worker_thread.join();
}

void SimEncoder::run() {
	while (!this->stop_thread) {
		this_thread::sleep_for(chrono::milliseconds(this->sim_enc_cycle_time));
		this->ticks = this->ticks + (this->motor->getPower()*this->sim_enc_cycle_time/1000*this->max_rps*this->resolution) / 100;
	}

}

long SimEncoder::getTicks() {
	return (long)this->ticks;
}

