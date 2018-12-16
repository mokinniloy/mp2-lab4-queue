#include "tqueue.h"
#include <iostream>

using namespace std;

TQueue::TQueue(int Size):TStack(Size)
{
    Li = -1;
}

TData TQueue::Get()
{
    TData tmp = -1;
    if(pMem == NULL)
        SetRetCode(DataNoMem);
    else if(IsEmpty())
        SetRetCode(DataEmpty);
    else
    {
        Li = GetNextIndex(Li);
        tmp = pMem[Li];
        --DataCount;
    }
    return tmp;
}

TData TQueue::TopElem()
{
    if(pMem == NULL)
    {
        SetRetCode(DataNoMem);
        return -1;
    }
    else if(IsEmpty())
    {
        SetRetCode(DataEmpty);
        return -1;
    }
    else
    {
        int tmpInd = GetNextIndex(Li);
        return pMem[tmpInd];
    }
}

void TQueue::Print()
{
    int tmp = Li;
    for(int i = 0; i < DataCount; i++)
    {
        cout<<pMem[tmp];
        tmp = GetNextIndex(tmp);
    }
}

int TQueue::GetNextIndex(int ind)
{
    return ++ind%MemSize;
}

int TQueue::GetSize() const
{
    return DataCount;
}

