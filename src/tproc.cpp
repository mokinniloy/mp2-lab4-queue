#include "tproc.h"

TProc::TProc(double q)
{
	q2 = q;
	distribution = uniform_real_distribution<double>(0.0, 1.0);
	process = false;
}

bool TProc::end_processing()
{
	return (distribution(generator) < q2);
}

bool TProc::in_process()
{
	return process;
}

void TProc::set_process(bool s)
{
	process = s;
}