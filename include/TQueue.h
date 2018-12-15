#include "tstack.h"
#define MaxMemSize 30

class TQueue : public TStack
{
private:
	int Hi, Li; // Li - index of first element. Hi - index of last element
public:
	TQueue(int Size = MaxMemSize);
	TQueue(const TQueue &q);
	~TQueue() {};
	void Put(const TData &Val);
	TData Get();
	int GetNextIndex(int index)const;
};
