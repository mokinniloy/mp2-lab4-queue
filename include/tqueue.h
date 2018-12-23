#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include "tstack.h"

class TQueue : public TStack {
 protected:
 int Li; // индекс начала очереди
 int Hi; //конец очереди
 int GetNextIndex (int index); // получить следующий индекс
public:
 TQueue (int Size = DefMemSize);
 TElem Get () ; // извлечь значение
 void Put(const TData &Val); //положить значение
 TElem TopElem ();
};

#endif // __TQUEUE_H__