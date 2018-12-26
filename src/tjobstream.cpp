#include "tjobstream.h"
#include <iostream>

TJobStream::TJobStream()
{
    q1 = 0;
    mt = std::mt19937(time(0));
    rand = std::uniform_real_distribution<double>(0, 1);
}

bool TJobStream::IsTask()
{

    q1 = rand(mt);
    if(q1 <= 0.5)
        return 1;
    else
        return 0;
}


int TJobStream::GetTask()
{
    return cnt++;
}
