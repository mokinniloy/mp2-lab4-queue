#include "tjobstream.h"
#include <iostream>

TJobStream::TJobStream(double _q1)
{
    q1 = _q1;
    mt = std::mt19937(time(0));
    rand = std::uniform_real_distribution<double>(0, 1);
}

bool TJobStream::IsTask()
{
    if(rand(mt) <= q1)
        return 1;
    else
        return 0;
}


int TJobStream::GetTask()
{
    return cnt++;
}
