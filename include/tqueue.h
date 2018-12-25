#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "tstack.h"

class TQueue : public TStack
{
private:
  int bottom;
  int _next_index(int ind);
public:
  TQueue(int Size = DefMemSize);
  ~TQueue() {};
  void Put(const TData &Val);
  TData Get();

  void Print();
};

#endif
