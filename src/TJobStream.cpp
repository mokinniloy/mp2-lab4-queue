#include "TJobStream.h"
//#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TJobStream.h"

TJobStream::TJobStream(double _q1)
{
	q1 = _q1;
	IdentificatorOfTask = 0;
}

bool TJobStream::IsThereNewTask(double RandomValue)
{
	if (RandomValue < q1)
	{
		return true;
	}
	else
		return false;
}

int TJobStream::RegisterNewTask()
{
	return ++IdentificatorOfTask;
}

int TJobStream::GetQuantityOfAllGeneratedTasks()
{
	return IdentificatorOfTask;
}
