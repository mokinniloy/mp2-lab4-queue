#pragma once
#include "tdataroot.h"

class TStack :public TDataRoot
{
protected:
		int Hi; // индекс последнего элемента структуры
		virtual int GetNextIndex(int Index);
public:
		TStack(int Size = DefMemSize) : TDataRoot(Size), Hi(-1) { }
		TStack(const TStack &);
		void Put(const TData &); // положить в стек
		TData Get(); //взять из стека
		int  IsValid();
		void Print();
		TData GetTopElem();
};