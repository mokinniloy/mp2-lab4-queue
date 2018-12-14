#ifndef __TPROC__
#define __TPROC__

#include <random>
#include <time.h>

class TProc
{
private:
    std::mt19937 gen;
    std::uniform_real_distribution<double> ran;
    double bar_val;
    bool task;
public:
    TProc(double barrier=0.5);
    ~TProc(){}
    bool task_ready();
    bool has_task()const;
    void push();
};

#endif // __TJOBSTREAM__
