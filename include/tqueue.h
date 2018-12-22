#ifndef __T_QUEUE__
#define __T_QUEUE__

#include "tstack.h"

class TQueue :public TStack
{
    private:
    int hi,li;
    public:
    TQueue(int size=DefMemSize);
    ~TQueue(){}
    void Put(const TData& Val);
    TData Get();
    TData TopElem();
    void Print();
};
#endif // __T_QUEUE__
