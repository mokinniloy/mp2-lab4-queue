#include "tjobstream.h"
#include "tproc.h"
#include "tqueue.h"
#include <iostream>
#include <iomanip>

const int CLOCKS = 1000000;

int main()
{
	TJobStream stream(0.5);
	TProc proc(0.5);
	TQueue queue;	// Default size equals 25
	int task_number = 0;
	int failure = 0;
	int downtime = 0;
	for (int i = 0; i < CLOCKS; ++i)
	{
		if (stream.isNewTaskReady())
		{
			task_number++;
			if (!queue.IsFull()) queue.Put(task_number);
			else failure++;
		}
		if (proc.isProcReady())
			if (!queue.IsEmpty()) queue.Get();
			else downtime++;
	}
	std::cout << "Tasks: " << task_number << " Denials: " << std::setprecision(4) << (static_cast<double>(failure) / task_number) * 100 << "%" << "Clocks/t: " << std::setprecision(4) << static_cast<double>(CLOCKS - downtime) / task_number << "Downtime: " << std::setprecision(4) << (static_cast<double>(downtime) / CLOCKS) * 100 << "%" << std::endl;
	return 0;
}