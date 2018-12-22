#include "TQueue.h"
 

int TQueue::GetNextIndex(int index)
{
	return ++index%MemSize;
}

TData TQueue::Get()
{
	TData temp = -1;
	if (pMem == nullptr) SetRetCode(DataNoMem);
	else if (IsEmpty()) {
		SetRetCode(DataEmpty);
		throw "cant_get_elem_when_its_empty";
	}
	else {
		temp = pMem[Li];
		Li = GetNextIndex(Li);
		DataCount--;
	}
	return temp;
}

TData TQueue::TopElem()
{
	TData  tmp = -1;
	if (pMem == nullptr) SetRetCode(DataNoMem);
	else if (IsEmpty()) SetRetCode(DataEmpty);
	else {
		tmp = pMem[Li];
	}

	return tmp;
}
