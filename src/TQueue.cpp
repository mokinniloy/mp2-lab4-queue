#include "../include/TQueue.h"

void TQueue::Put(const TData &val)
{
	if (IsFull())
	{
		SetRetCode(DataFull);
		return;
	}
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return;
	}
	last = getNextIndex(last);
	pMem[last] = val;
	DataCount++;
}

TData TQueue::Get()
{
	if (pMem == nullptr) SetRetCode(DataNoMem);
	else if (IsEmpty()) SetRetCode(DataEmpty);
	else
	{
		TData temp = pMem[first];
		first = getNextIndex(first);
		DataCount--;
		return temp;
	}
}

int TQueue::getNextIndex(int index)
{
	return (index + 1) % MemSize;
}