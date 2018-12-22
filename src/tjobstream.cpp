#include "tjobstream.h"
#include <cstdlib>
#include <ctime>

TJobStream::TJobStream(double q1, double q2)
{
	if ((q1 < 0) || (q2 < 0) || (q1 >= 1) || (q2 >= 1))
		throw "Error:incorrect value";
	boundValue = q2;
	boundTask = q1;
	tasknum = 0;
}

int TJobStream::taskGeneration()
{
	return (((double)rand() / RAND_MAX) < boundTask) ? ++tasknum : 0;
}

int TJobStream::taskWork()
{
	return (((double)rand() / RAND_MAX) < boundValue) ? 1 : 0;
}

int TJobStream::getTaskNum()
{
	if (tasknum == 0)
		throw "Error";
	return tasknum;
}