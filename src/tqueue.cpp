#include "tqueue.hpp"
#include <stdexcept>
#include <cstring>

TQueue::TQueue(int size) : TStack(size)
{
	Li = 0;
}

void TQueue::Put(const TData& element)
{
	if (IsValid() < 0)
		throw std::logic_error("No memory");

	if (IsFull())
	{
		SetRetCode(DataFull);
		throw std::range_error("Stack is full");
	}
	else
	{
		if (top == MemSize)
		{
			top = GetNextIndex(top);
			pMem[top] = element;
		}
		pMem[++top] = element;
		DataCount++;
		SetRetCode(DataOK);
	}
}

TData TQueue::Get()
{
	if (IsValid() < 0)
		throw std::logic_error("No memory");

	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		throw std::range_error("Queue is empty");
	}
	else
	{
		auto temp = pMem[Li];
		if (Li == MemSize)
		{
			pMem[Li] = 0;
			Li = GetNextIndex(Li);
		}
		else
			pMem[Li++] = 0;

		SetRetCode(DataOK);
		DataCount--;
		return temp;
	}
}

int TQueue::GetNextIndex(int index)
{
	return ++index % (MemSize + 1);
}

