#include "tqueue.hpp"
#include <stdexcept>
#include <cstring>

TQueue::TQueue(int size) : TStack(size)
{
    Li = 0;
}

void TQueue::Put(const TData& element)
{
    try
    {
        TStack::Put(element);
    }
    catch (const std::range_error& exception)
    {
        if (std::strncmp(exception.what(), (char*)"Stack if full", 13) && DataCount != MemSize)
        {
            GetNextIndex(top);
            TStack::Put(element);
        }
    }
}

TData TQueue::Get()
{
    if (IsValid() < 0)
        throw std::logic_error("No memory");

    if (IsEmpty())
    {
        SetRetCode(DataEmpty);
        throw std::range_error("Queue is empty");
    }
    
    auto temp = pMem[Li];
    if (Li == MemSize)
    { 
        pMem[Li] = 0;
        GetNextIndex(Li);
    }
    else
        pMem[Li++] = 0;

    SetRetCode(DataOK);
    DataCount--;
    
    return temp;
}

int TQueue::GetNextIndex(int& index)
{
    return ++index % (MemSize + 1);
}

