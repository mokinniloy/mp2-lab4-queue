#include "tdataroot.h"

class TStack : public TDataRoot
{
protected:
	int Hi;
	virtual int GetNextIndex(int index);
public:
	TStack(int Size = DefMemSize);
	~TStack() {};
	virtual void Put(const TData &Val);
	virtual TData Get();
	virtual TData TopElem();

	int IsValid();
	void Print();
};