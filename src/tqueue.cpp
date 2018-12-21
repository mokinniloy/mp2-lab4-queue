#include "tqueue.h"

TQueue::TQueue(int size) : TStack(size)
{
	if (size > 0)
	{
		lowIndex = 0;
		highIndex = 0;
	}
	else
		throw "error";
}

int TQueue::Get()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return 0;
	}
	else
	{	
		
		TData tmp = pMem[lowIndex];
		lowIndex = GetNextIndex(lowIndex);
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
		pMem[highIndex] = val;
		highIndex = GetNextIndex(highIndex);
		DataCount++;
	}
}

int TQueue::GetNextIndex(int index)
{
	return ++index % MemSize;
}
