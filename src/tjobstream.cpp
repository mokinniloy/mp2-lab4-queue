#include "tjobstream.h"

TJobStream::TJobStream(int lenght) : TQueue(lenght)
{
	distribution = std::uniform_real_distribution<double>(0.0, 1.0);
	q1 = 0;
	failAddNum = 0;
}

bool TJobStream::TryToAdd(int n)//переделать
{
	//srand(time(NULL));
	if (distribution(generator) < q1)
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