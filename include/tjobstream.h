#pragma once
#include <random>
#include <ctime>

class TJobStream
{
private:

	int tasknum;  //index zadaniya
	double boundValue; //пороговое значение
	double boundTask; //порог задачи

public:

	TJobStream(double q1, double q2);
	int taskGeneration(); //Генерация задачи
	int getTaskNum(); //индекс значения
	int taskWork(); //генерация завершения обработки

};