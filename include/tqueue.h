#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "tstack.h"

class TQueue: public TStack
{
private:
    int Li;
public:
    TQueue(int Size = DefMemSize);
    ~TQueue() {};
    TData Get();
    TData TopElem();
    void Print();
    int GetSize() const;
private:
    int GetNextIndex(int ind);
};

#endif // __QUEUE_H__
