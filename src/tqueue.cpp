#include "tqueue.h"

TQueue::TQueue(int Size):TStack(Size)
{
	hi = -1;
	li = -1;
}

void TQueue::Put(const TData & Val)
{
	if (IsFull())
	{
		SetRetCode(DataFull);
		throw"Queue is full";
	}
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		throw "Stracture don't have memort";
	}
	else
	{
		hi = GetNextIndex(hi);
		pMem[hi] = Val;
		DataCount++;
	}
}

void TQueue::Put(const int & Val)
{
	if (IsFull())
	{
		SetRetCode(DataFull);
		throw"Queue is full";
	}
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		throw "Stracture don't have memory";
	}
	else
	{
		hi = GetNextIndex(hi);
		pMem[hi].SetCyclesOnTask(Val);
		DataCount++;
	}
}

TData TQueue::Get()
{
	TData temp;
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		throw "Stracture don't have memory";
	}
	if (!IsEmpty())
	{
		li = GetNextIndex(li);
		temp = pMem[li];
		DataCount--;
	}
	else
		throw "Queue is empty";
	return temp;
}

int TQueue::GetNextIndex(int ind)
{
	return (++ind % MemSize);
}
