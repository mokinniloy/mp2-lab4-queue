#include "tstack.h"
  
   class TQueue : public TStack
  {
  protected:
  	int Hi;
  	int Li;
  	int GetNextIndex(int index);
  public:
  	TQueue(int Size = DefMemSize);
  	void Put(const TData& val);
  	TData Get();
  	TData TopElem();
  	void Print();
  };