#include "TJobStream.h"
#include <cstdlib>
#include <ctime>

TJobStream::TJobStream(double q1 , double q2)
{
	if ((q1 < 0) || (q2 < 0) || (q1 >= 1) || (q2 >= 1))
		throw "incorrect value";
	boundOfExecution = q2;
	boundOfTasks = q1;
	taskNum = 0;
}

int TJobStream::taskGeneration()
{
	return (((double)rand() / RAND_MAX) < boundOfTasks) ? ++taskNum : 0;
}

int TJobStream::taskWork()
{
	return (((double)rand() / RAND_MAX) < boundOfExecution) ? 1 : 0;
}

int TJobStream::getTaskNum()
{
	if (taskNum == 0)
		throw "task not created";
	return taskNum;
}
