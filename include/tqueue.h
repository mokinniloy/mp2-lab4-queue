#include "tstack.h"

class TQueue : public TStack
{
private:
	int Li;
public:
	TQueue(int Size = DefMemSize);
	TData Get();

	void Print();
};