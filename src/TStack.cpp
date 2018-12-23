#include "/../include/TStack.h"
#include <iostream>

void TStack::Put(const TData &val)
{
	if (IsFull())
	{
		SetRetCode(DataFull);
		return;
	}
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return;
	}
	pMem[DataCount++] = val;
}

TData TStack::Get()
{
	if (pMem == nullptr) SetRetCode(DataNoMem);
	else if (IsEmpty()) SetRetCode(DataEmpty);
	else return pMem[--DataCount];
}

void TStack::Print()
{
	for (int i = 0; i < DataCount; ++i)
		std::cout << pMem[i] << " ";
	std::cout << std::endl;
}