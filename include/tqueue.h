#pragma once
#include "tstack.h"

class TQueue : public TStack
{
private:
	int high_index;
	int low_index;
public:
	TQueue(int size);
	virtual void Put(int val);
	virtual TData Get();
	virtual TData TopElem();
	int GetNextIndex(int index);
};

