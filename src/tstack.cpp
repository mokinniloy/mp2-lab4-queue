#include "tstack.h"
#include <iostream>

using namespace std;

TStack::TStack(int Size):TDataRoot(Size)
{
    Hi = -1;
}

void TStack::Put(const TData &Val)
{
    if(pMem == NULL)
        SetRetCode(DataNoMem);
    else if(IsFull())
        SetRetCode(DataFull);
    else
    {
        Hi = GetNextIndex(Hi);
        pMem[Hi] = Val;
        ++DataCount;
    }
}

TData TStack::Get()
{
    TData tmp = -1;
    if(pMem == NULL)
        SetRetCode(DataNoMem);
    else if(IsEmpty())
        SetRetCode(DataEmpty);
    else
    {
       tmp = pMem[Hi--];
       --DataCount;
    }
    return tmp;
}

TData TStack::TopElem()
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
        return pMem[Hi];
}

int TStack::IsValid()
{
    return GetRetCode();
}

void TStack::Print()
{
    for(int i = 0; i <= Hi; i++)
        cout<<pMem[i]<<" ";
    cout<<"\n";
}

int TStack::GetNextIndex(int ind)
{
    return ++ind;
}
