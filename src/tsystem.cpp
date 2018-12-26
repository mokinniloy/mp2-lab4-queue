#include "tsystem.hpp"
#include <iostream>

TSystem::TSystem()
{
	skippedTasks = completedTasks = taskCount = 0;
	idleClocks = busyClocks = clockCount = 0;
	cpuTreshold = taskTreshold = 0.0;
}

void TSystem::simulate(int totalClocks, int queueSize, double cpuTshold, double taskTshold)
{
	cpuTreshold = cpuTshold;
	taskTreshold = taskTshold;

	cpu = TCpuThread(cpuTreshold);
	taskThread = TTaskThread(taskTreshold);
	cpuQueue = TQueue(queueSize);

	clockCount = totalClocks;

	for (auto i = 0; i < clockCount; i++)
	{
		auto task = taskThread.tick();
		auto cpuTick = cpu.tick();

		if (task)
		{
			taskCount++;

			if (!cpuQueue.IsFull())
				cpuQueue.Put(task);
			else
				skippedTasks++;
		}

		if (cpuTick)
		{
			if (cpu.GetState() == BUSY)
				completedTasks++;

			cpu.SetState(IDLE);
		}

		if (cpu.GetState() == IDLE)
		{
			if (!cpuQueue.IsEmpty())
			{
				cpuQueue.Get();
				cpu.SetState(BUSY);
			}
		}

		cpu.GetState() == BUSY ? busyClocks++ : idleClocks++;
	}

	while (!cpuQueue.IsEmpty())
	{
		cpuQueue.Get();
		skippedTasks++;
	}

	if (skippedTasks + completedTasks != taskCount)
		completedTasks += taskCount - (skippedTasks + completedTasks);
}

void TSystem::printResults()
{
	std::cout << "Clock count: " << clockCount << std::endl;
	std::cout << "Busy clocks: " << busyClocks << std::endl;
	std::cout << "Idle clocks: " << idleClocks << "\033[91m(" << (double)idleClocks / (double)clockCount * 100 << "%)\033[0m" << std::endl;

	std::cout << "Task count: " << taskCount << std::endl;
	std::cout << "Completed tasks: " << completedTasks << std::endl;
	std::cout << "Skipped tasks: " << skippedTasks << "\033[91m(" << (double)skippedTasks / (double)taskCount * 100 << "%)\033[0m" << std::endl;

	std::cout << "Av. clocks/task: " << (double)busyClocks / completedTasks << std::endl;
}