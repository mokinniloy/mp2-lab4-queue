#include <stdio.h>
#include "tstack.h"
#include <iostream>


TStack::TStack(int Size) : TDataRoot(Size)
{
	top = -1;
}

int TStack::GetNextIndex(int index)
{
	return ++index;
}

void TStack::Put(const TData &Val)
{
	if (IsFull()) SetRetCode(DataFull);
	else if (pMem == NULL) SetRetCode(DataNoMem);
	else
	{
		top = GetNextIndex(top);
		pMem[top] = Val;
		DataCount++;
	}
}

TData TStack::Get()
{
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return 0;
	}
	else if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return 0;
	}
	else
	{
		DataCount--;
		std::cout<<"Get " << pMem[top] << std::endl;
		return pMem[top--];
	}
}

TData TStack::TopElem()
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
		return pMem[top];
	}
}

int TStack::IsValid() 
{
	return GetRetCode();
}

void TStack::Print()
{
	for (int i = 0; i < DataCount; ++i)
		std::cout << pMem[i] << " ";
	std::cout << "\n";
}

