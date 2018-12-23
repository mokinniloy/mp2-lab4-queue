#include <stdio.h>
#include <iostream>
#include "tqueue.h"

TQueue::TQueue(int Size) : TStack(Size) {
    Li = Hi = -1;
}

int TQueue :: GetNextIndex (int index) {
	return (index + 1) % MemSize;
}

 TElem TQueue :: Get ( void ) { // извлечь значение
	 if (IsEmpty()) 
		 RetCode = DataEmpty;
	 else {
		 int result = pMem[Li];
		 Li = GetNextIndex(Li);
		 DataCount--;
		 return result;
	 }
 }

 void TQueue :: Put(const TData &Val) {
	 if (IsFull()) 
		 RetCode = DataFull;
	 else {
		 if (Li==-1) Li++;
		 Hi = GetNextIndex(Hi);
		 pMem[Hi] = Val;
		 DataCount++;
	 }
 }

 TElem TQueue :: TopElem () {
	 return this->pMem[Li];
 }