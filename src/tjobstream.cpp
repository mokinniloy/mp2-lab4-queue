#include "tjobstream.h"

TJobStream::TJobStream(double q)
{
	q1 = q;
	distribution = uniform_real_distribution<double>(0.0, 1.0);
	task_id = 0;
}

int TJobStream::generate()
{
	if (distribution(generator) < q1)
		return ++task_id;
	else
		return -1;
}