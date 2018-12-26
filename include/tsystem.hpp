#pragma once
#include "tqueue.hpp"
#include "ttaskthread.hpp"
#include "tcputhread.hpp"

class TSystem
{
private:
	int skippedTasks, completedTasks, taskCount;
	int idleClocks, busyClocks, clockCount;
	double cpuTreshold, taskTreshold;

	TQueue cpuQueue;
	TTaskThread taskThread;
	TCpuThread cpu;
public:
	TSystem();
	~TSystem() {};

	void simulate(int totalClocks, int queueSize, double cpuTshold, double taskTshold);
	void printResults();
};