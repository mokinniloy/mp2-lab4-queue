#include "tdataroot.h"

class TStack :public TDataRoot
{
private:
	int top; 
public:
    TStack(int Size = DefMemSize);
    ~TStack() {};
	void Put(const TData &Val); 
	void Put(const int &Val);
	TData Get();
	virtual TData TopElem(); 
	int IsValid();
        void Print();
};
