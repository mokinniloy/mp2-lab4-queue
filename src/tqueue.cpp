#include "tqueue.h"

#include <iostream>



int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize; // "%" - îñòàòîê îò äåëåíèÿ. ñì î÷åðåäü íà êîëüöåîì áóôåðå
}

TData TQueue::Get()
{
	TData tmp = -1;
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	else
	{
		if (IsEmpty())
			SetRetCode(DataEmpty);
		else
		{
			tmp = this->pMem[Li];
			Li = this->GetNextIndex(Li);
			this->DataCount--;
		}
	}
	return tmp;
}


void TQueue::Print()
{
	int t = DataCount;
	for (int i = Li; i != Hi; i = GetNextIndex(i))
	{
		//t--;
		std::cout << pMem[i] << " ";
	}
	std::cout << std::endl;
};
