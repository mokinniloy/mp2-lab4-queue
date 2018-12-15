#include "tqueue.hpp"
#include <stdexcept>

TQueue::TQueue(int size) : TStack(size)
{
    Hi = -1;
    Li = 0;
}

void TQueue::Put(const TData& element)
{
    TStack::Put(element);
    GetNextIndex(Hi);
}

TData TQueue::Get()
{
    if (TQueue::IsValid() < 0)
        throw std::logic_error("No memory");

    if (TQueue::IsEmpty())
    {
      SetRetCode(DataEmpty);
      throw std::range_error("Queue is empty");
    }

    SetRetCode(DataOK);
    auto temp = pMem[Li];
    pMem[GetNextIndex(Li)] = 0;

    return temp;
}

int TQueue::GetNextIndex(int& index)
{

}

int TQueue::IsValid()
{

}

bool TQueue::IsEmpty()
{

}

