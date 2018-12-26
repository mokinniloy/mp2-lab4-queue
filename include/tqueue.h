#pragma once
#include "tstack.h"

class TQueue : public TStack
{
private:
	int lowIndex;						//нижний индекс
	int highIndex;						//верхний индекс
public:
	TQueue(int size);
	virtual void Put(int val);			//добавление эл-та
	virtual int Get();					//удаление эл-та
	int GetNextIndex(int val);			//получение след. индекса
};

