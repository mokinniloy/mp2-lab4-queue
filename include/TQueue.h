#include "../include/TStack.h"

class TQueue : public TStack
{
public:
	TQueue(int size = DefMemSize) : TStack(size){first = 0; last = -1;}
	~TQueue() = default;
	void Put(const TData &Val) override;
	TData Get() override;

private:
	int first;
	int last;
	int getNextIndex(int index);
};