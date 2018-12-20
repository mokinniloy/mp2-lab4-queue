#include "tstack.h"
#define MaxMemSize 30

class TQueue : public TStack
{
private:
	int Li, Hi; // Li - index of first element. Hi - index of last element (Get - Li; Put - Hi)
public:
	TQueue(int Size = MaxMemSize) : TStack(Size) { Li = 0; Hi = 0; };
	int GetNextIndex(int index)const;
	TData Get(); //we must to override inhereted Get() method for queue class
	void Put(const TData &val);
	TData TopElem();
	void Print();
};
