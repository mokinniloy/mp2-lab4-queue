#include "tdataroot.h"

class TStack :public TDataRoot
{
private:
	int top;
public:
	TStack(int size);
	virtual void Put(const TData &Val);
	virtual TData Get();
	virtual TData TopElem();

	int IsValid();
	void Print();
};