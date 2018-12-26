#include "tproc.h"

TProc::TProc(double _q2)
{
	q2 = _q2;
	mt = std::mt19937(time(0));
	rand = std::uniform_real_distribution<double>(0, 1);
	Empty = 1;
}

bool TProc::IsComplete()
{
	if (rand(mt) <= q2)
		return 1;
	else
		return 0;
}

bool TProc::IsEmpty()
{
	return Empty;
}

void TProc::Busy()
{
	Empty = 0;
}

void TProc::Ready()
{
	Empty = 1;
}
