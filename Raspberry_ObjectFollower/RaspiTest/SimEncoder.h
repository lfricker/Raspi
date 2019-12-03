#pragma once
#include<atomic>
#include<thread>
#include<chrono>
#include"SimMotor.h"
#include "Encoder.h"
class SimEncoder : public Encoder
{
private:
	const double max_rps = 1;
	SimMotor* motor;
	const long resolution = 20;
	const long sim_enc_cycle_time = 100;
	std::atomic<bool> stop_thread;
	std::atomic<double> ticks;
	std::thread worker_thread;

	void run();

public:
	~SimEncoder();
	long getTicks();
	SimEncoder(SimMotor* motor);

};

