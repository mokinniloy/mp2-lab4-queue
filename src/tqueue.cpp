#include "tqueue.h"

#include <iostream>

TQueue::TQueue(int Size) : TStack(Size), bottom(-1) {}

void TQueue::Put(const TData &Val)
{
  if(TDataRoot::IsFull())
    throw DataFull;

  TDataRoot::DataCount++;

  if(TDataRoot::IsFull())
    TDataCom::SetRetCode(DataFull);

  TDataRoot::pMem[TStack::top = _next_index(TStack::top)] = Val;
}

TData TQueue::Get()
{
  if(TDataRoot::IsEmpty())
    throw DataEmpty;

  TDataRoot::DataCount--;

  if(TDataRoot::IsEmpty())
    TDataRoot::SetRetCode(DataEmpty);

  return TDataRoot::pMem[bottom = _next_index(bottom)];
}

void TQueue::Print()
{
 std::cout << "queue";
}

int TQueue::_next_index(int ind)
{
  return (ind + 1) % TDataRoot::MemSize;
}
