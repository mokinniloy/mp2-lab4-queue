//#include "TQueue.h"
#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TQueue.h"

TQueue::TQueue(int Size)
{
	if (Size < 0)
		throw "Negative Size of Queue";
	Hi = 0;
	Li = 0;
	MemSize = Size;
	DataCount = 0;
	pMem = new TElem[MemSize];
}

TQueue::TQueue(const TQueue & q)
{
	Li = q.Li;
	Hi = q.Hi;
	MemSize = q.MemSize;
	DataCount = q.DataCount;
	pMem = new TData[MemSize];
	for (int i = 0; i < MemSize; i++)
	{
		pMem[i] = q.pMem[i];
	}
}

void TQueue::Put(const TData & Val) // overriding
{
	if (DataCount == MemSize)
		throw "Queue is full during Put call";
	Hi = GetNextIndex(Hi);
	pMem[Hi] = Val;
	DataCount++;
}

TData TQueue::Get() // overriding
{
	if (DataCount == 0)
		throw "Queue is empty during Get() call";
	int OldLi = Li;
	Li = GetNextIndex(Li);
	DataCount--;
	return pMem[OldLi];
}

int TQueue::GetNextIndex(int index) const
{
	if (index == MemSize - 1)
		return 0;
	else
		return ++index;
}

