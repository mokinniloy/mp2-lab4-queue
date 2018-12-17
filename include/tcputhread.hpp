#pragma once
#include <random>

#define IDLE 0
#define BUSY 1

class TCpuThread
{
private:
	std::default_random_engine generator;
	std::uniform_real_distribution<double> range;

	double tresholdValue;
	int currentState;
public:
	TCpuThread() { range = std::uniform_real_distribution<double>(0.0, 1.0); }
	TCpuThread(double treshold);
	~TCpuThread() {}

	int tick() { return range(generator) < tresholdValue; }

	bool GetState() { return currentState; }
	void SetState(bool state) { currentState = state; }
};