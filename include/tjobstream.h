#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

#include <random>
#include <ctime>

class TJobStream
{
    double q1;
    int cnt = 0;
    std::mt19937 mt;
    std::uniform_real_distribution<double> rand;
public:
    TJobStream();
    bool IsTask();
    int GetTask();
};

#endif // __JOBSTREAM_H__
