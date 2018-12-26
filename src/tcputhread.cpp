#include "tcputhread.hpp"
#include <functional>
#include <stdexcept>
#include <chrono>

TCpuThread::TCpuThread(double treshold)
{
	if (treshold < 0 || treshold > 1)
		throw std::range_error("Unexpected treshold");

	tresholdValue = treshold;
	currentState = IDLE;
}
