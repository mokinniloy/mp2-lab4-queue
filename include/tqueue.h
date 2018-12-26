

#include "tstack.h"

class TQueue : public TStack
{
protected:
	int Li;
	int Hi;
	virtual int GetNextIndex(int index);
public:
	TQueue(int Size = DefMemSize) : TStack(Size) { Li = 0; }
	virtual TData Get(); //взятие с удалением
	//virtual void Put(const TData &val);
	void Print();
};