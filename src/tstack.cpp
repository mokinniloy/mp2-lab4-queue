#include <iostream>
#include "tstack.h"

using namespace std;

int TStack::GetNextIndex(int index)
{
	return ++index;
}

TStack::TStack(int Size) : TDataRoot(Size)
{
	Hi = -1;
}

void TStack::Put(const TData &Val)
{
	if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
	}
	else if (IsFull())
	{
		SetRetCode(DataFull);
	}
	else
	{
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		DataCount++;
	}
}

TData TStack::Get()
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
		DataCount--;
		return pMem[Hi--];
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
		return pMem[Hi];
	}
}

int TStack::IsValid()
{
	return GetRetCode();
}

void TStack::Print()
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
		for (int i = 0; i < DataCount; i++)
		{
			cout << pMem[i] << ' ';
		}
	}
}