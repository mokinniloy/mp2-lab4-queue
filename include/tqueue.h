#include "tstack.h"

class TQueue: public TStack
{
private:
	int first;

public:
	TQueue(int s = 5);

	TData Get();
};