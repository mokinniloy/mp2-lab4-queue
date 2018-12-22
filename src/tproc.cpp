#include "tproc.h"
#include "tjobstream.h"

TProc::TProc()
{
	tactsWork = 0;
	tactsFree = 0;
}

int TProc::GetWorkTacts()
{
	return tactsWork;
}

int TProc::GetFreeTacts()
{
	return tactsFree;
}

void TProc::SetBusy(TQueue &queue)
{
	if (queue.IsEmpty())
		tactsFree++;
	else
		tactsWork++;
}