#include "tjobstream.h"

TJobStream::TJobStream(int size,double barrier):num_tasks(size),bar_val(barrier),
ran(std::move(std::uniform_real_distribution<double>(0.0,1.0))),
gen(std::move(std::mt19937(time(0))))
{
    cur_task=0;
}

int TJobStream::size()const
{
    return num_tasks;
}

bool TJobStream::is_empty()const
{
    return cur_task>=num_tasks;
}

int TJobStream::next()
{
    if (is_empty())
        return -1;
    if (ran(gen)<bar_val)
        return -1;
    return cur_task++;
}
