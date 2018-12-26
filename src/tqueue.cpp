#include "tqueue.h"

int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize;
}

TQueue::TQueue(int Size) : TStack(Size)
{
	Li = 0;
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
	else
	{
		int tmp = Li;
		Li = GetNextIndex(Li);
		DataCount--;
		return pMem[tmp];
	}
}

TData TQueue::TopElem()
{
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
	}
	else
	{
		return pMem[Li];
	}
}
