#include "tjobstream.h"
#include <iostream>

using namespace std;

TJobStream::TJobStream(double q) : q1(q)
{}

bool TJobStream::NewJob()
{
	double r = (rand() / (double)(RAND_MAX + 1));
	if (r <= q1)
	{
		jobNum++;
		return 1;
	}
	else
		return 0;
}


int TJobStream::GetNum()
{
	return jobNum;
}