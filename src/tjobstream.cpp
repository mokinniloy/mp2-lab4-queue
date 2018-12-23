#include "tjobstream.h"
#include <iostream>

using namespace std;

TJobStream::TJobStream(double q)
{
	q1 = q;
	task_num = 0;
}

bool TJobStream::GetNewTask()
{
	if (double(rand()) / double(RAND_MAX) < q1)
	{
		task_num++;
		return 1;
	}
	return 0;
}

int TJobStream::GetTaskNum() const
{
	return task_num;
}