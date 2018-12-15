#include "tstack.h"

class TQueue : public TStack
{
private:
    int Hi;                             //верхний индекс
    int Li;                             //нижний индекс
public:
    TQueue(int size = DefMemSize);
    ~TQueue() {};

    void Put(const TData& element);
    TData Get();
    int GetNextIndex(int& index);

    int IsValid();
    bool IsEmpty();
};