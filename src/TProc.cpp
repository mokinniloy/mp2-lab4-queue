//TProc.cpp
#include "TProc.h"
#include <random>
#include <ctime>

using namespace std;

TProc::TProc(double q) 
{
	is_busy = false;
	q2 = q;
	k2 = uniform_real_distribution <double>(0, 1);
	generator = mt19937(time(0) + 1);
}

int TProc::tact() 
{
	if (k2(generator) < q2) return 1;
	else return 0;
}

bool TProc::get_busy()const
{
	return is_busy;
}

void TProc::set_busy(bool s)
{
	is_busy = s;
}