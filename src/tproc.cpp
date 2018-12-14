#include "tproc.h"

TProc::TProc(double barrier):bar_val(barrier),
ran(std::move(std::uniform_real_distribution<double>(0.0,1.0))),
gen(std::move(std::mt19937(time(0)+1)))
{
    task=false;
}

bool TProc::task_ready()
{
    if (has_task())
    {
        bool fl=ran(gen)>bar_val;
        if (fl)
            task=false;
        return fl;
    }
    return 0;
}

bool TProc::has_task()const
{
    return task;
}

void TProc::push()
{
    task=true;
}
