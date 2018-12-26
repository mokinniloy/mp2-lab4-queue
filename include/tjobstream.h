#include "tqueue.h"
#include <stdlib.h>
#include <random>

class TJobStream : protected TQueue
{
protected:
	float q1; // âåðîÿòíîñòü ïîÿâëåíèÿ íîâîé êîìàíäû
	int failAddNum; // êîëè÷åñòâî îòêàçîâ
	int comandToDoNum;// êîëè÷åñòâî ïîñòóïèâøèõ êîìàíä
	
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution;
	
public:
	TJobStream(int lenght);
	bool TryToAdd(int n);
	void SetQ1(float x);
};
