#pragma once
#include "tdataroot.h"
#include <random>
#include <ctime>

class TJobStream
{
private:
	int taskIndex;						//индекс задачи
	double boundOfExecution;			//порог генерации завершения обработки
	double boundOfTasks;				//порог генерации задачи
	
public:
	TJobStream(double q1 , double q2);
	int taskGeneration();				//генерация задачи
	int taskWork();						//генерация завершения обработки
	int getTaskIndex();					//возвращение индекса задачи
};

