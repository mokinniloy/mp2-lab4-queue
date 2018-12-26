#include "tqueue.h"

using namespace std;

TQueue::TQueue(int Size) :TStack(Size), Li(-1), Hi(-1)
{}

TData TQueue::Get()
{
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	else if (IsEmpty())
		SetRetCode(DataEmpty);
	else
	{
		--DataCount;
		Li = GetNextIndex(Li);
		return pMem[Li];
	}

}

void TQueue::Put(const TData &Val)
{
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	else if (IsFull())
		SetRetCode(DataFull);
	else
	{
		++DataCount;
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
	}
}

TData TQueue::TopElem()
{
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return -1;
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return -1;
	}
	else
	{
		return pMem[GetNextIndex(Li)];
	}
}


int TQueue::GetNextIndex(int index)
{
	return (index + 1) % MemSize;
}