#include "tcputhread.hpp"
#include <stdexcept>
#include <functional>
#include <chrono>

TCpuThread::TCpuThread()
{
  tresholdValue = 0;
  currentState = IDLE;
}

TCpuThread::TCpuThread(double treshold)
{
    if (treshold < 0 || treshold > 1)
        throw std::range_error("Unexpected treshold");

    tresholdValue = treshold;
    currentState = IDLE;

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    generator = std::mt19937(seed);
    range = std::uniform_real_distribution<double> (0.0, 1.0);
}

int TCpuThread::tick()
{
    return range(generator) < tresholdValue;
}

bool TCpuThread::GetState()
{
    return currentState;
}

void TCpuThread::SetState(bool state)
{
    currentState = state;
}
