#include "iostream"
#include "tqueue.h"

using namespace std;

TQueue::TQueue(int Size): TStack(Size), Li(-1) {}

int TQueue::GetNextIndex(int ind) const
{
	return (++ind) % MemSize;
}

TData TQueue::Get()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return -1;
	}
	else if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return -1;
	}
	else
	{
		DataCount = DataCount - 1;
		Li = GetNextIndex(Li);
		return pMem[Li];
	}
}

TData TQueue::TopElem()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return -1;
	}
	else if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return -1;
	}
	else
	{
		int tmp = GetNextIndex(Li); // Li не должен двигаться
		return pMem[tmp];
	}
}

void TQueue::Print()
{
	for (int i = Li; i != Hi; i = GetNextIndex(i))
	{
		cout << pMem[i] << " ";
	}
	cout << endl;
}