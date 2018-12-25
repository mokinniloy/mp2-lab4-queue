#pragma once
#include <random>
#include <ctime>

class TProc {
private:
	std::mt19937 generate;                    // генерация значения датчика
	double upper_bound;                       // некое пороговое значение
	bool proc_busy;                           // занятость процессора
public:
	TProc(double q2);                         // конструктор с неким пороговым значением
	bool Tact();                              // такт
	bool GetBusy();                           // получить занятость процессора
	void SetBusy(bool arg);                   // установить занятость процессора
};

