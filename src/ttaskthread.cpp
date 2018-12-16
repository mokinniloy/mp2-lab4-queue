#include "ttaskthread.hpp"
#include <functional>
#include <stdexcept>
#include <chrono>

TTaskThread::TTaskThread()
{
  taskID = 0;
  tresholdValue = 0;
}

TTaskThread::TTaskThread(double treshold)
{
    if (treshold < 0 || treshold > 1)
        throw std::range_error("Unexpected treshold");

    taskID = 0;
    tresholdValue = treshold;

    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    generator = std::mt19937(seed);
    range = std::uniform_real_distribution<double> (0.0, 1.0);
}

int TTaskThread::tick()
{
    return (range(generator) < tresholdValue) ? ++taskID : 0;
}