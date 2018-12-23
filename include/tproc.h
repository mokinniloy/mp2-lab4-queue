#include "tdataroot.h"
#include "tqueue.h"
#include "tjobstream.h"

class TProc
{
public:
	TProc();
	int GetCountOfWorkTacts();				//вернуть кол-во тактов работы
	int GetCountOfFreeTacts();				//вернуть кол-во тактов простоя
	void BusyOfProc(TQueue &queue);	    //проверка на занятость
private:
	int tactsOfWork;						//такты работы
	int tactsOfFree;						//такты простоя

};

