#include "tjobstream.h"
#include <cstdlib>
#include <ctime>

TJobStream::TJobStream(double q1 , double q2)
{
	if ( (q1 > 1)||(q2 > 1)||(q1 < 0) || (q2 < 0) )
		throw "incorrect value";
	boundOfTasks = q1; //велечина регулирующая интенсивность потока заданий
	boundOfExecution = q2; //величинахарактеризующую производительность процессора
	taskIndex = 0;
}

int TJobStream::taskGeneration()
{
	return (((double)rand() / RAND_MAX) < boundOfTasks) ? ++taskIndex : 0;
}

int TJobStream::taskWork()
{
	return (((double)rand() / RAND_MAX) < boundOfExecution) ? 1 : 0;
}

int TJobStream::getTaskIndex()
{
	if (taskIndex == 0)
		throw "task not created";
	return taskIndex;
}
