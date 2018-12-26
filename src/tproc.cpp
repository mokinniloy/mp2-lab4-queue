#include "tproc.h"

TProc::TProc(double p)
{
	if (p < 0 || p > 1)
		throw - 1;
	Productivity = p;
	Free = true;
}

int TProc::RunRequest(int Val)
{
	TProc::Ti = Val;
	unsigned s = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(s);
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	double dist = distribution(generator);
	if (dist < Productivity)
		return 1;
	else
		return 0;
}

