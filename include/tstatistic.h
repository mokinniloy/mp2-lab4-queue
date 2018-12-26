#pragma once
#include"tjobstream.h"
class TStatistic
{
protected:
	int amountOfAddedTask; // номер добавленного задания
	int amountDoneTask; //Количество выполненных заданий
	int amountIgnoreTask; //Количество проигнорированных заданий
	int clocksOfIdle; //кол-во тактов простоя
	int amountOfClocks;// количество тактовых циклов
	int clocksTarget; // количество заданных тактовых циклов 
public:
	TStatistic();
	~TStatistic() {};
	static void GetStatistic(int amountOfClocksOfTest,int clockFrequencyMhz, 
		TJobStream& task, int qSize, int intensivityInOut);
	
};