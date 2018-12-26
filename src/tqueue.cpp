#include <iostream>
#include "tqueue.h"

TQueue::TQueue(int Size) : TStack(Size) {
	li = hi = 0;
}

void TQueue::Put(const TData &Val) {
	if (!IsFull()) {
		RetCode = DataOK;
		pMem[hi] = Val;
		hi = (hi + 1) % MemSize;
		++DataCount;
	}
	else {
		RetCode = DataFull;
	}
}

TData TQueue::Get() {
	if (!IsEmpty()) {
		RetCode = DataOK;
		TData retValue = pMem[li];
		li = (li + 1) % MemSize;
		--DataCount;
		return retValue;
	}
	else {
		RetCode = DataEmpty;
	}
}

int TQueue::IsValid() {
	return true;
}

TData TQueue::TopElem() {
	return pMem[(hi - 1 + MemSize) % MemSize];
}

void TQueue::Print() {
	for (int i = li, cnt = 0; cnt != DataCount; i = (i + 1) % MemSize, ++cnt)
		std::cout << pMem[i] << " ";
	std::cout << std::endl;
}