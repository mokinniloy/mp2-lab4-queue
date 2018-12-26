#include "ttaskthread.hpp"
#include <functional>
#include <stdexcept>
#include <chrono>

TTaskThread::TTaskThread(double treshold)
{
	if (treshold < 0 || treshold > 1)
		throw std::range_error("Unexpected treshold");

	taskID = 0;
	tresholdValue = treshold;
}