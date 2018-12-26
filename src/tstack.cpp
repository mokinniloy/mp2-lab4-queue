#include "tstack.h"
#include <stdexcept>
#include <iostream>

TStack::TStack(int Size)
{

	if (Size == 0)
	{
		MemSize = DefMemSize;
		pMem = new TData[MemSize];
		top = -1;
	}
	else if (Size > 0)
	{
		MemSize = Size;
		pMem = new TData[MemSize];
		top = -1;
	}
	else
		throw "ERR";
}

/*TStack::TStack(const TStack &a)
{
	MemSize = a.MemSize;
	pMem = new int[MemSize];
	top = a.top;
	std::copy(a.pMem, a.pMem + MemSize, pMem);
}*/

void TStack::Put(const TData &Val)
{
	if (IsValid() < 0)
		throw "no memory";
	if (IsFull())
		throw "stack is full";
	else
	{
		pMem[++top] = Val;
		DataCount++;
	}
}

TData TStack::Get()
{
	if (IsValid() < 0)
	{
		throw "no memory";
		return -1;
	}
	if (IsEmpty())
	{
		throw "stack is empty";
		return -1;
	}
	else
	{
		DataCount--;
		return pMem[top--];
	}
}

TData TStack::TopElem()
{
	if (IsValid() < 0)
		throw "no memory";
	if (IsFull())
		throw "stack is full";
	else
		return pMem[top];
}

int TStack::IsValid()
{
	if (pMem == NULL)
		return SetRetCode(DataNoMem);
	if (MemSize == 0)
		return SetRetCode(DataNoMem);
	return 1;
}

void TStack::Print()
{
	for (int i = 0; i < MemSize; i++)
		std::cout << pMem[i];
	std::cout << "\n";
}