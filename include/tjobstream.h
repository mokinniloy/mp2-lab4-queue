#include "tqueue.h"
#include <stdlib.h>
#include <time.h>

class TJobStream : protected TQueue
{
protected:
	float q1; // вероятность появления новой команды
	unsigned long int failAddNum; // количество отказов
	unsigned long int comandToDoNum;// количество поступивших команд
public:
	TJobStream(int lenght);
	bool TryToAdd(int n);
	void SetQ1(float x);
};