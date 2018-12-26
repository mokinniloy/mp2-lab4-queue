#include <iostream>
#include "tstack.h"

TStack::TStack(int Size) :TDataRoot(Size)
{
	Hi = -1;
}

void TStack::Put(const TData &Val)
{
	if (pMem == NULL)
		SetRetCode(DataNoMem);
	else if (IsFull())
		SetRetCode(DataFull);
	else
	{
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		++DataCount;
	}
}

TData TStack::Get()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
	}
	else {
		--DataCount;
		return pMem[Hi--];
	}
}

TData TStack::TopElem()
{
	if (pMem == NULL)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
	}
	else return pMem[Hi];
}

int TStack::IsValid() {
	return true;
}

void TStack::Print()
{
	for (int i = 0; i <= Hi; i++)
		std::cout << pMem[i] << " ";
	std::cout << std::endl;
}

int TStack::GetNextIndex(int ind)
{
	return ++ind;
}