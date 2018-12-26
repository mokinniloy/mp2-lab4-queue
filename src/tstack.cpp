#include <iostream>
#include "tstack.h"

using namespace std;

TStack::TStack(int Size) : TDataRoot(Size), Hi(-1) {}

int TStack::GetNextIndex(int ind) const
{
	return ++ind;
}

void TStack::Put(const TData &Val)
{
	if (IsFull())
	{
		SetRetCode(DataFull);
	}
	else if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
	}
	else
	{
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		DataCount = DataCount + 1;
	}
}

TData TStack::Get()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return -1;
	}
	else if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return -1;
	}
	else
	{
		DataCount = DataCount - 1;
		return pMem[Hi--];
	}
}

TData TStack::TopElem()
{
	if (IsEmpty())
	{
		SetRetCode(DataEmpty);
		return -1;
	}
	else if (pMem == nullptr)
	{
		SetRetCode(DataNoMem);
		return -1;
	}
	else
	{
		return pMem[Hi];
	}
}

int TStack::IsValid()
{
	return RetCode;
}

void TStack::Print()
{
	for (int i = 0; i < DataCount; ++i)
	{
		cout << pMem[i] << " ";
	}
	cout << endl;
}