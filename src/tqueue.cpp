#include "tqueue.h"
#include <iostream>

TQueue::TQueue(int s): TStack(s)
{
	first = 0;
}

int TQueue::GetNextIndex(int ind)
{
	return ++ind % MemSize;
}

TData TQueue::Get() 
{
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
	}
	else {//?????????????????????
		DataCount--;
		int t = first;
		first = GetNextIndex(first);
		//first = GetNextIndex(first);
		return pMem[t];
	}
}