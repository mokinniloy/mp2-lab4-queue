#include<iostream>
#include "tstack.h"

TStack::TStack(int Size):TDataRoot(Size)
{
	top = -1;
	for (int i = 0; i < MemSize; i++)
		pMem[i].SetCyclesOnTask(0);
}

void TStack::Put(const TData & Val)
{
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	if (!IsFull())
	{
		pMem[++top] = Val;
		DataCount++;
	}
	else
	{
		SetRetCode(DataFull);
		throw "Stack is full";
	}
}

void TStack::Put(const int & Val)
{
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	if (!IsFull())
	{
		pMem[++top].SetCyclesOnTask(Val);
		DataCount++;
	}
	else
	{
		SetRetCode(DataFull);
		throw "Stack is full";
	}
}

TData TStack::Get()
{
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	if (!IsEmpty())
	{
		TData temp = pMem[top];
		top--;
		DataCount--;
		return temp;
	}
	else
	{
		SetRetCode(DataEmpty);
		throw "Stack is empty";
	}
}

TData TStack::TopElem()
{
	if (pMem == nullptr)
		SetRetCode(DataNoMem);
	if (!IsEmpty())
		return pMem[top];
	else
	{
		SetRetCode(DataEmpty);
		throw "Stack is empty";
	}
}

int TStack::IsValid()
{
	if (pMem == NULL)
	{
		std::cout << "Stracture don't have memory";
		return 1;
	}
	if (MemSize >= DataCount)
	{
		std::cout << "Structure is Valid" << std::endl;
		this->Get();
		return 1;
	}
	else
		return 0;
}

void TStack::Print()
{
	if (!IsEmpty())
	{
		int a = pMem[top].GetCyclesOnTask();
		std::cout << (pMem[top].GetCyclesOnTask()) << std::endl;
		std::cout << "top -> " << pMem[top].GetCyclesOnTask() << std::endl;
		for (int i = top - 1; i > 0; i--)
			std::cout << pMem[i].GetCyclesOnTask() << std::endl;
	}
}
