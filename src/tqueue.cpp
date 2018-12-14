#include "tqueue.h"
#include <iostream>

TQueue::TQueue(int size):TStack(size)
{
    hi=li=0;
}

void TQueue::Put(const TData& Val)
{
    if (pMem==NULL)
    {
        SetRetCode(DataNoMem);
        throw DataNoMem;
    }
    if (IsFull())
    {
        SetRetCode(DataFull);
        throw DataFull;
    }
    ++DataCount;
    pMem[hi]=Val;
    hi=(hi+1)%MemSize;
}

TData TQueue::Get()
{
    if (pMem==NULL)
    {
        SetRetCode(DataNoMem);
        throw DataNoMem;
    }
    if (IsEmpty())
    {
        SetRetCode(DataEmpty);
        throw DataEmpty;
    }
    --DataCount;
    int tmp=li;
    li=(li+1)%MemSize;
    return pMem[tmp];
}

TData TQueue::TopElem()
{
    if (pMem==NULL)
    {
        SetRetCode(DataNoMem);
        throw DataNoMem;
    }
    if (IsEmpty())
    {
        SetRetCode(DataEmpty);
        throw DataEmpty;
    }
    return pMem[li];
}

void TQueue::Print()
{
    if (IsEmpty())
        return;
    int i=li;
    do
    {
        std::cout << pMem[i] << ' ';
        i=(i+1)%MemSize;
    }
    while(i!=hi);
}
