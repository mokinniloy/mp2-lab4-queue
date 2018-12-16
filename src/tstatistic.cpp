#include<iostream>
#include "tstatistic.h"
#include"tproc.h"

TStatistic::TStatistic()
{
	amountOfAddedTask = 0;
	amountDoneTask = 0;
	amountIgnoreTask = 0;
	amountOfClocks = 0;
	clocksOfIdle = 0;
	clocksTarget = 0;
}
void TStatistic::GetStatistic(int amountOfClocksOfTest, int clockFrequencyMhz,
	TJobStream& task,int qSize,int intensivityInOut)
{
	TProc proc(clockFrequencyMhz,amountOfClocksOfTest,qSize, intensivityInOut);
	while (amountOfClocksOfTest > proc.amountOfClocks)
		proc.DoClock(task);
	int amountOfAllTask = proc.amountIgnoreTask + proc.amountOfAddedTask; // количество всех задач
	std::cout << "Amount of added tasks = " << proc.amountOfAddedTask << std::endl;
	std::cout << "Amount of done tasks = " << proc.amountDoneTask << std::endl;
	std::cout << "Amount of ignore tasks = " << proc.amountIgnoreTask << std::endl;
	std::cout << "Percent of ignore Tasks = " << (proc.amountIgnoreTask /
		static_cast<double>(amountOfAllTask)) * 100 << "%" << std::endl;
	std::cout << "Amount of clocks = " << proc.amountOfClocks << std::endl;
	std::cout << "Amount of clocks idle = " << proc.clocksOfIdle << std::endl;
	std::cout << "Percent of idle = " << (proc.clocksOfIdle /
		static_cast<double>(proc.amountOfClocks)) * 100 << "%" << std::endl;
	std::cout << std::endl;
	std::cout << "Amount of all tasks = " << amountOfAllTask << std::endl;
	int clocksOfDoing = proc.amountOfClocks - proc.clocksOfIdle;
	float averageClocks = static_cast<float>(clocksOfDoing) / proc.amountDoneTask;
	std::cout << "Amount average clocks = " << averageClocks << std::endl;

}
