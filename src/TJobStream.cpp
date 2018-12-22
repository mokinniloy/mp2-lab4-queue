#include "TJobStream.h"
#include<ctime>
#include <random>

using namespace std;

TJobStream::TJobStream(double q) 
{
	task_id = 0;
	q1 = q;
	k1 = uniform_real_distribution <double>(0, 1);
	generator = mt19937(time(0) + 1);
}

int TJobStream::generate() 
{
	if (k1(generator) < q1) return ++task_id;
	else return -1;
}