#pragma once
#include"tstack.h"
class TQueue:public TStack
{
private:
	int hi;
	int li;
public:
	TQueue(int Size);
	void Put(const TData &Val);
	void Put(const int &Val);
	TData Get();
	int GetNextIndex(int ind);
};