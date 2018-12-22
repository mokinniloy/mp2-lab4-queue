#include "TJobStream.h"

TJobStream::TJobStream(double q)
{
	q1 = q;
	dstrbtshn = std::uniform_real_distribution<double>(0.0, 1.0);
	task_id = 0;
}

int TJobStream::Generate()
{
	return (dstrbtshn(mt) < q1)? ++task_id : 0 ;
}
