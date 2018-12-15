#include "tqueue.hpp"
#include <stdexcept>

TQueue::TQueue(int size) : TStack(size)
{
    Hi = -1;
    Li = 0;
}

void TQueue::Put(const TData& element)
{
    if (IsValid() < 0)
        throw std::logic_error("No memory");

    if (IsFull())
        throw std::range_error("Queue is full");

    pMem[GetNextIndex(Hi)] = element;
    DataCount++;

    SetRetCode(DataOK);
}

TData TQueue::Get()
{
    if (IsValid() < 0)
        throw std::logic_error("No memory");

    if (IsEmpty())
        throw std::range_error("Queue is empty");

    auto temp = pMem[Li];
    pMem[GetNextIndex(Li)] = 0;
    DataCount--;

    return temp;
}

int TQueue::GetNextIndex(int& index)
{
    return ++index % MemSize;
}

