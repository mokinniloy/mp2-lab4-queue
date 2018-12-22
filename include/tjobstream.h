#ifndef __TJOBSTREAM__
#define __TJOBSTREAM__

#include <random>
#include <time.h>

class TJobStream
{
private:
    std::mt19937 gen;
    std::uniform_real_distribution<double> ran;
    double bar_val;
    int cur_task;
    int num_tasks;
public:
    TJobStream(int size,double barrier=0.5);
    ~TJobStream(){}
    int size()const;
    bool is_empty()const;
    int next();
};

#endif // __TJOBSTREAM__
