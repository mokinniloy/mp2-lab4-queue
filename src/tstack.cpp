#include "tstack.h"
#include <iostream>

TStack::TStack(int size)
{
	if (size == 0)
	{
		MemSize = DefMemSize;
		pMem = new TData[MemSize];
		top = -1;
	}
	else if (size > 0)
	{
		MemSize = size;
		pMem = new TData[MemSize];
		top = -1;
	}
	else
		throw "ERR";
}
/*-------------------------------------------------------------------------*/
void TStack::Put(const TData &Val)
{
	if (IsFull())
		SetRetCode(DataErr);
	else
	{
		DataCount++;
		pMem[++top] = Val;
	}
}
/*-------------------------------------------------------------------------*/
TData TStack::Get()
{
	if (IsEmpty())
	{
		SetRetCode(DataErr);
		return -1;
	}
	else
	{
		DataCount--;
		return pMem[top--];
	}
}
/*-------------------------------------------------------------------------*/
TData TStack::TopElem()
{
	if (IsEmpty())
	{
		SetRetCode(DataErr);
		return -1;
	}
	else
		return pMem[top];
}
/*-------------------------------------------------------------------------*/
int TStack::IsValid()
{
	int res = 0;
	if (pMem == NULL)         res  = 1;
	if (MemSize < DataCount)  res += 2;
	return res;
}
/*-------------------------------------------------------------------------*/
void TStack::Print()
{
	for (int i = 0; i < DataCount; i++)
		std::cout << pMem[i] << std::endl;
	std::cout << std::endl;
}