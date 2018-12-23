#include "tproc.h"
#include <iostream>

using namespace std;

TProc::TProc(double q)
{
	q2 = q;
	status = 1;
}

bool TProc::SolveTask()
{
	if (double(rand()) / double(RAND_MAX) < q2)
	{
		return 1;
	}
	return 0;
}

bool TProc::IsReady() const
{
	return status;
}

void TProc::TakeNewTask()
{
	status = 0;
}

void TProc::ComplitedTask()
{
	status = 1;
}