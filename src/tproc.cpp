#include "tproc.h"
#include "tjobstream.h"

TProc::TProc()
{
	tactsOfWork = 0;
	tactsOfFree = 0;
}

int TProc::GetCountOfWorkTacts()
{
	return tactsOfWork;
}

int TProc::GetCountOfFreeTacts()
{
	return tactsOfFree;
}

void TProc::BusyOfProc(TQueue &queue)
{
	if (queue.IsEmpty())
		tactsOfFree++;
	else
		tactsOfWork++;
}