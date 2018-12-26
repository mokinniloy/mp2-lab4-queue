#pragma once
#include"tqueue.h"
#include"tstatistic.h"
const int DEFAULT_FREQUENCY = 1000;
class TProc :public TStatistic
{
private:
	int clockFrequency; //тактовая частота Mhz
	int qSize; // длина очередей
	int intensivityInOut; //интенсивность потока задач
	TQueue* queueIn; // Очереди in
	TQueue* queueOut; // Очереди out
	int CycleOnTask(TJobStream& b);
	bool AddTask(TJobStream& b);
	bool DoTask(TJobStream& b);
public:
	TProc(int clockFrequencyMhz, int clocksTarget,int qSize = 4,int intensivityInOut = 2);
	TProc();
	~TProc();
	void DoClock(TJobStream& b);
};