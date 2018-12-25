#include "tqueue.h"
#include <iostream>



TQueue::TQueue(int size) : TStack(size)
{
	if (size > 0)
	{
		high_index = 0;
		low_index = 0;
	}
	else
		throw "ERR";
}
/*----------------------------------------------------------------------*/
void TQueue::Put(int val)
{
	if (IsFull())
		SetRetCode(DataFull);
	else
	{
		pMem[high_index] = val;
		GetNextIndex(high_index);
		DataCount++;
	}
}
/*----------------------------------------------------------------------*/
TData TQueue::Get()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return 1;
	}
	else
	{
		TData tmp = pMem[low_index];
		DataCount--;
		GetNextIndex(low_index);
		return tmp;
	}
}
/*----------------------------------------------------------------------*/
int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize;
}

TData TQueue::TopElem()
{
	if (IsEmpty())
		SetRetCode(DataEmpty);
	else
		return pMem[low_index];
}
