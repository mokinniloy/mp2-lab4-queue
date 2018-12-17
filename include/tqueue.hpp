#pragma once
#include "tstack.h"

class TQueue : public TStack
{
private:
	int Li;                             //начало очереди
public:
	TQueue(int size = DefMemSize);
	~TQueue() {};

	void Put(const TData& element);
	TData Get();

	int GetNextIndex(int index);
};