#include <iostream>
#include "tproc.h"


using namespace std;

TProc::TProc(double q) :q2(q)
{}

bool TProc::IsFree()
{
	return state;
}

bool TProc::IsDone()
{
	double r = (rand() / (double)(RAND_MAX + 1));
	if (r <= q2)
		return 1;
	else
		return 0;
}

void TProc::StartJob()
{
	state = 0;
}

void TProc::EndJob()
{
	state = 1;
}