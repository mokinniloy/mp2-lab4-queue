#pragma once
#include <random>

class TTaskThread
{
private:
	std::default_random_engine generator;
	std::uniform_real_distribution<double> range;

	int taskID;
	double tresholdValue;
public:
	TTaskThread() { range = std::uniform_real_distribution<double>(0.0, 1.0); }
	TTaskThread(double treshold);
	~TTaskThread() {}

	int tick() { return (range(generator) < tresholdValue) ? ++taskID : 0; }
};