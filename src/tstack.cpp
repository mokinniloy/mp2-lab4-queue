#include <stdio.h>
#include <iostream>
#include "tstack.h"

TStack :: TStack (int size)
{
	if (size<0) throw -1;
	if (size==0) 
		this -> pMem = NULL;
	else 
		this -> pMem = new TElem [size];
	this -> MemSize = size;
	this-> DataCount = 0;
	top = -1;
}

void TStack::Put(const TData& Val)  {
	if (IsFull()) 
		SetRetCode(DataFull);
	if (pMem==NULL)
		SetRetCode(DataNoMem);
	if (this->RetCode==DataOK) {
		top++;
		pMem[top] = Val;
		DataCount++;
	}
}

TData TStack::Get() {
	if (IsEmpty()) 
		SetRetCode(DataEmpty);
	if (pMem==NULL)
		SetRetCode(DataNoMem);
	if (this->RetCode==DataOK) {
		DataCount--;
		return pMem[top--];
	}
}

TData TStack::TopElem() {
	if (IsEmpty()) 
	{
		SetRetCode(DataEmpty);
		throw -1;
	}
	if (pMem==NULL) 
	{
		SetRetCode(DataNoMem);
		throw -1;
	}
	return pMem[top];
}


int TStack:: IsValid() {
	return GetRetCode();
}

void TStack::Print() {
	if (IsEmpty()) std::cout<<"-"; 
	for (int i = 0; i < DataCount; i++)
		std::cout<<(char)pMem[i]<<" ";
	std::cout<<std::endl;
}