#include <cstdlib>
#include "TJobStream.h"

double DoubleRand(double max, double min)
{
	return min + double(rand()) / RAND_MAX * (max - min);
}


TJobStream::TJobStream(double Intens)
{
	if (Intens < 0 || Intens > 1) throw - 1;
	q1 = Intens;
}

int number = 0;
int TJobStream::GetNewJob()
{
	if (DoubleRand(1, 0) < q1) return ++number;
	else return 0;
}

double TJobStream::GetQ1()
{
	return q1;
}