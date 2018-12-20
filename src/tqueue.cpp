#include "tqueue.h"

TQueue::TQueue(int Size) : TStack(Size)
{
	Li = 0;
}

TData TQueue::Get()
{
	if (GetRetCode() != DataOK)
	{
		SetRetCode(DataErr);
		return NULL;
	}
	if (this->IsEmpty())
	{
		TDataCom::SetRetCode(DataEmpty);
		return -1;
	}
	TData tmp = pMem[Li];
	Li = GetNextIndex(Li);
	DataCount--;
	return tmp;
}

void TQueue::Print()
{
	int i = Li;
	while (i != Hi)
	{
		std::cout << pMem[i] << ' ';
		i = GetNextIndex(i);
	}
	std::cout << pMem[Hi] << std::endl;
}