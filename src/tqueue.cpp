#include "tqueue.h"
#include <iostream>

TQueue::TQueue(int size) : TStack(size)
{
	if (size > 0)
	{
		low_index = 0;
		high_index = 0;
	}
	else
		throw "error";
}

int TQueue::Get()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return 1;
	}
	else
	{

		TData tmp = pMem[low_index];
		low_index = GetNextIndex(low_index);
		DataCount--;
		return tmp;
	}
}

void TQueue::Put(int val)
{
	if (IsFull())
		SetRetCode(DataFull);
	else
	{
		pMem[high_index] = val;
		high_index = GetNextIndex(high_index);
		DataCount++;
	}
}

int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize;
}