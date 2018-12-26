#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "tstack.h"

class TQueue : public TStack
{
public:
	int Li;
	int Hi;

	TQueue(int Size = DefMemSize);
	~TQueue() {};
	TData Get();
	void Put(const TData &Val);
	TData TopElem();
	int GetNextIndex(int ind);
};

#endif 