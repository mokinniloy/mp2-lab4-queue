#include <tqueue.h>
#include <iostream>
using namespace std;
int TQueue::GetNextIndex(int index)
{
	return ++index%MemSize;
};

TData TQueue::Get()
{
	TData tmp = -1;
	if (pMem == 0) SetRetCode(DataNoMem);
	else if (IsEmpty()) SetRetCode(DataEmpty);
	else
	{
		tmp = pMem[Li];
		Li = GetNextIndex(Li);
		DataCount--;
	}
	return tmp;
};

void TQueue::Put(const TData& val)
{
	if (IsFull()) SetRetCode(DataFull);
	else if (pMem == 0) SetRetCode(DataNoMem);
	else
	{
		pMem[Hi] = val;
		Hi = GetNextIndex(Hi);
		DataCount++;
	}
};
TData TQueue::TopElem()
{
	TData tmp = -1;
	if (IsEmpty()) SetRetCode(DataEmpty);
	else
		tmp = pMem[Li];
	return tmp;
}
void TQueue::Print()
{
	int t = DataCount;
	for (int i = Li; i != Hi, t != 0; i = GetNextIndex(i))
	{
		t--;
		std::cout << pMem[i] << " ";
	}
	cout << endl;
};
