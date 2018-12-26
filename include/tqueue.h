#include "tstack.h"

class TQueue: public TStack
{
private:
	int first;
	int GetNextIndex(int ind);
public:
	TQueue(int s = DefMemSize);
	~TQueue() {};
	TData Get();
	
};