#pragma once
#include <atomic>
#include <thread>
#include <chrono>
#include <wiringPi.h>
#include "Encoder.h"


class RPiEncoder : public Encoder
{
private:
	int BCM_pin;
	int current;
	int previous;
	std::atomic<bool> stopThread;
	std::atomic<long> ticks;
	std::thread workerThread;

	void run();

public:
	RPiEncoder(int BCM_pin);
	~RPiEncoder();
	long getTicks();
};

