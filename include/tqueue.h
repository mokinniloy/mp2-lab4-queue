#include "tstack.h"
#include <iostream>

class TQueue :public TStack
{
private:
	int Hi;
	int Li;
public:
	TQueue(int size = DefMemSize);
	~TQueue() {}
	void Put(const TData &Val);
	TData Get();
	virtual TData TopElem();
	void Print();
};