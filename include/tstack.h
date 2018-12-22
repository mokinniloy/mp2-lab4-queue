#include "tdataroot.h"

class TStack :public TDataRoot
{
protected:
	int Hi;  //индекс последнего элемента структуры
	virtual int GetNextIndex(int index); //получить следующее значение индекса
public:
    TStack(int Size = DefMemSize);
    ~TStack() {};
	void Put(const TData &Val); //положить в стек
	TData Get(); //взять из стека с удалением
	virtual TData TopElem(); 

	int IsValid();
    void Print();
};