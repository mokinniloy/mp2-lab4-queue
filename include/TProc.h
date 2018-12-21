#include "tdataroot.h"
#include "tqueue.h"
#include "TJobStream.h"

class TProc
{
private:
	int tactsOfWork;						//такты работы
	int tactsOfFree;						//такты простоя
public:
	TProc();
	int GetCountOfWorkTacts();				//вернуть кол-во тактов работы
	int GetCountOfFreeTacts();				//вернуть кол-во тактов простоя
	void BusynessOfProc(TQueue &queue );	//проверка на занятость
};

