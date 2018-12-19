#include "tjobstream.h"

TJobStream::TJobStream(int lenght) : TQueue(lenght)
{
	q1 = 0;
	failAddNum = 0;
}

bool TJobStream::TryToAdd(int n)//переделать
{
	srand(time(NULL));
	if ((rand() % 100) / (100 * 1.0) < q1)
	{
		comandToDoNum++;
		if (!IsFull() && pMem != nullptr)
		{
			Put(n);
			return true;
		}
		else
		{
			failAddNum++;
			return false;
		}
	}
	return false;
	
}

void TJobStream::SetQ1(float x)
{
	if (x <= 0 || x > 1)
		throw - 1;
	q1 = x;
}