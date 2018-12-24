#include "tqueue.h"

TQueue::TQueue(int size)
{
	Hi = 0;
	Li = 0;
}
void TQueue::Put(const TData &Val)
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
		throw - 1;
	}
	if (IsFull())
	{
		SetRetCode(DataFull);
		throw - 1;
	}
	++DataCount;
	pMem[Hi] = Val;
	Hi = (Hi + 1) % MemSize;
}
TData TQueue::Get()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
		throw - 1;
	}
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		throw - 1;
	}
	--DataCount;
	int tmp = Li;
	Li = (Li + 1) % MemSize;
	return pMem[tmp];
}
TData TQueue::TopElem()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
		throw - 1;
	}
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		throw - 1;
	}
	return pMem[Li];
}
void TQueue::Print()
{
	if (IsEmpty()) return;
	int i = Li;
	do
	{
		std::cout << pMem[i] << ' ';
		i = (i + 1) % MemSize;
	} while (i != Hi);
}