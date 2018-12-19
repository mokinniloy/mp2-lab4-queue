#include "tdataroot.h"

class TStack :public TDataRoot
{

protected:
//	virtual int GetNextIndex(int index);
	int top;
	virtual int GetNextIndex(int index);
public:
    TStack(int Size = DefMemSize);
    ~TStack() {};
	void Put(const TData &Val); 
	TData Get();
	virtual TData TopElem(); 

	int IsValid();
    void Print();
};