#include "tqueue.h"
#include <iostream>

using namespace std;

int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize;
}

void TQueue::Put(const TData &Val)
{
	if (pMem == nullptr)
		throw SetRetCode(DataNoMem);
	else if (IsFull())
		throw SetRetCode(DataFull);
	else
	{
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		DataCount++;
	}
}

TData TQueue::Get()
{
	if (pMem == nullptr)
		throw SetRetCode(DataNoMem);
	else if (IsEmpty())
		throw SetRetCode(DataEmpty);
	else
	{
		DataCount--;
		TData tmp = pMem[Li];
		GetNextIndex(Li);
		return tmp;
	}
}

TData TQueue::GetTopElem()
{
	if (pMem == nullptr)
		throw SetRetCode(DataNoMem);
	else if (IsEmpty())
		throw SetRetCode(DataEmpty);
	else
		return pMem[Li];
}