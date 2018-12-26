#ifndef __STACK_H__
#define __STACK_H__

#include "tdataroot.h"

class TStack: public TDataRoot
{
private:
	int Hi;
public:
    TStack(int Size = DefMemSize);
    ~TStack() {};
	void Put(const TData &Val);
	virtual TData Get();
	virtual TData TopElem();
	int IsValid();
    void Print();
private:
    virtual int GetNextIndex(int ind);
};
#endif // __STACK_H__