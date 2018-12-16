#pragma once
#include <random>

class TTaskThread
{
private:
    std::mt19937 generator;
    std::uniform_real_distribution<double> range;

    int taskID;
    double tresholdValue;
public:
    TTaskThread();
    TTaskThread(double treshold);
    ~TTaskThread() {};

    int tick();
};