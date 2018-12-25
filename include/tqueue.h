#include <tstack.h>

class TQueue : public Stack
{
protected:
	int Li, Hi;
	virtual int GetNextIndex(int index);
public:
	TQueue(int Size = DefMemSize) : Stack(Size) {
		Li = 0; Hi = 0;
	}
	virtual void Put(const TData& val);
	virtual TData Get();
	virtual TData TopElem();
	virtual void Print();
};