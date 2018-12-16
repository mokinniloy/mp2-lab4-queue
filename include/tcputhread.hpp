#pragma once
#include <random>

#define IDLE 0
#define BUSY 1

class TCpuThread
{
private:
    std::mt19937 generator;
    std::uniform_real_distribution<double> range;

    double tresholdValue;
    int currentState;
public:
    TCpuThread();
    TCpuThread(double treshold);
    ~TCpuThread() {};

    int tick();

    bool GetState();
    void SetState(bool state);
};