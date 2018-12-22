#pragma once
#include "tstack.h"
class TQueue :
	public TStack
{
protected:
	int Li;   //индекс первого элемнета структуры
	virtual int GetNextIndex(int index); //получить следующий индекс
public:
	TQueue(int Size = DefMemSize) : TStack(Size) {Li=0;};
	virtual TData Get();
	virtual TData TopElem();
};

