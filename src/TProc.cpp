#include "TProc.h"
#include "TJobStream.h"

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

void TProc::BusynessOfProc(TQueue &queue)
{
	if (queue.IsEmpty())
		tactsOfFree++;
	else
		tactsOfWork++;
}