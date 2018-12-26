#include "TProc.h"

TProc::TProc(double q)
{
	q2 = q;
	dstrbtshn = std::uniform_real_distribution<double>(0.0, 1.0);
	//process = false;
	 process = false;
}

bool TProc::end_process()
{
	return dstrbtshn(mt) <q2;
}
