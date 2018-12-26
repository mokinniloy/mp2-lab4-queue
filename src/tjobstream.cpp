#include "tjobstream.h"

TJobStream::TJobStream(double q)
{
	q_min = q;
	distribution = uniform_real_distribution<double>(0.0, 1.0);
	id = 0;
}

int TJobStream::generate()
{
	if (distribution(gen) < q_min)
		return ++id;
	else
		return -1;
}