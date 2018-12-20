#include "TProc.h"

TProc::TProc(double Rate)
{
	if (Rate < 0 || Rate > 1) throw - 1;
	q2 = Rate;
}

int TProc::IsProcBusy()
{
	if (DoubleRand(1, 0) < q2) return 0;
	else return 1;
}

/*int TProc::RunNewJob(int JobId)
{

}*/

double TProc::GetQ2()
{
	return q2;
}