#pragma once
#include <random>
#include <ctime>

class TJobStream
{
private:
	std::mt19937 generate_value;             // генерация значения датчика
	double upper_bound;                      // некое пороговое значение
	int task_number;                         // индекс задания
public:
	TJobStream(double q1);                   // конструктор с неким пороговым значением
	int Tact();                              // такт
};

