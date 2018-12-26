#pragma once
#include "tstack.h"

class TQueue : public TStack
{
private:

	int low_index;
	int high_index;

public:
	TQueue(int size);
	virtual void Put(int val);
	virtual TData Get();
	int GetNextIndex(int index);
};