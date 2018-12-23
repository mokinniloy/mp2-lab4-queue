#include "tstack.h"
#include <iostream>

using namespace std;

int TStack::GetNextIndex(int index)
{
	return ++index;
}

TStack::TStack(const TStack &st)
{
	DataCount = st.DataCount;
	MemSize = st.MemSize;
	MemType = st.MemType;
	pMem = new TElem[MemSize];
	for (int i = 0; i < DataCount; i++)
		pMem[i] = st.pMem[i];
}

void TStack::Put(const TData &Val)
{
	if (pMem == nullptr)
		throw SetRetCode(DataNoMem);
	else
	{
		if (IsFull())
		{
			void* p = new TElem[MemSize + DefMemSize];
			SetMem(p, MemSize + DefMemSize);
		}
		Hi = GetNextIndex(Hi);
		pMem[Hi] = Val;
		DataCount++;
	}
}

TData TStack::Get()
{
	if (pMem == nullptr)
		throw SetRetCode(DataNoMem);
	else if (IsEmpty())
		throw SetRetCode(DataEmpty);
	else
	{
		DataCount--;
		return pMem[Hi--];
	}
}

int  TStack::IsValid()
{
	int res = 0;
	if (pMem == nullptr)
		res++;
	if (MemSize < DataCount)
		res += 2;
	return res;
}

void TStack::Print()
{
	if (DataCount == 0)
		cout << "Stack is empty!";
	for (int i = 0; i < DataCount; ++i)
		cout << pMem[i] << " ";
	cout << endl;
}

TData TStack::GetTopElem()
{
	if (pMem == nullptr)
		throw SetRetCode(DataNoMem);
	else if (IsEmpty())
		throw SetRetCode(DataEmpty);
	else
		return pMem[Hi];
}