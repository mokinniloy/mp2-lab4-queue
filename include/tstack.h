#ifndef __TSTACK_H__
#define __TSTACK_H__

#include "tdataroot.h"

class TStack : public TDataRoot
{
protected:
	int Hi;

public:
	TStack(int Size);
	int GetHi();
	~TStack();
	void Put(const TData & Val);
	TData Get();
	TData& operator[](int i);
	int GetNextIndex(int index);

	int IsValid();
	void Print();
};

#endif


