#ifndef __TQUEUE_H__
#define __TQUEUE_H__
#include "tstack.h"

class TQueue : public TStack {
private:
	int li, hi;
public:
	TQueue(int Size = DefMemSize);
	~TQueue() {};
	void Put(const TData &Val);
	TData Get();
	TData TopElem() override;
	int IsValid();
	void Print();
};


#endif // __TQUEUE_H__