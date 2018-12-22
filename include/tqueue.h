#include "tstack.h"

class TQueue : public TStack
{
private:
	int Li;
	int GetNextIndex(int ind) const;
public:
	TQueue(int Size = DefMemSize);
	~TQueue() {};
	TData Get();
	TData TopElem();
	void Print();
};