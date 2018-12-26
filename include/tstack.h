#ifndef __TSTACK_H__
#define __TSTACK_H__
#include "tdataroot.h"

class TStack :public TDataRoot
{
private:
	int Hi;

	virtual int GetNextIndex(int ind);
public:
	TStack(int Size = DefMemSize);
	~TStack() {};
	void Put(const TData &Val);
	virtual TData Get();
	virtual TData TopElem();

	int IsValid();
	void Print();
};

#endif // __TSTACK_H__#pragma once
