//#include "TQueue.h"
#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TQueue.h"
#include <iostream>
using namespace std;

TData TQueue::Get() 
{
	if (DataCount == 0)
		throw "Queue is empty during Get() call";
	TData temp = pMem[Li];
	Li = GetNextIndex(Li);
	DataCount--;
	return temp;
}

void TQueue::Put(const TData & val)
{
	if (DataCount == MemSize)
		throw "Queue is full";
	Hi = GetNextIndex(Hi);
	pMem[Hi] = val;
	DataCount++;
}

int TQueue::GetNextIndex(int index) const
{
	if (index == MemSize - 1)
		return 0;
	else
		return ++index;
	// or just return ++index % MemSize;
}

TData TQueue::TopElem()
{
	if (DataCount == 0)
		throw "Queue is empty during TopElem() call";
	return pMem[Hi];
}

void TQueue::Print()
{
	for (int i = 0, counter = 0; counter != DataCount; i = GetNextIndex(i), counter++)
	{
		cout << pMem[i] << ' ';
	}
	cout << endl;
}
