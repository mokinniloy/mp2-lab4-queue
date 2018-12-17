#include "tproc.h"



TProc::TProc(double q2) : upper_bound(q2)
{
	generate = std::mt19937(time(0));
	proc_busy = false;
}
/*-------------------------------------------------------------*/
bool TProc::Tact()
{
	return std::uniform_real_distribution<double> {0, 1} (generate) < upper_bound;
}
/*-------------------------------------------------------------*/
bool TProc::GetBusy()
{
	return proc_busy;
}
/*-------------------------------------------------------------*/
void TProc::SetBusy(bool arg)
{
	proc_busy = arg;
}
/*-------------------------------------------------------------*/
