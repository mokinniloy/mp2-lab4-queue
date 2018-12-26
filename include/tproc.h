#pragma once
#include "tdataroot.h"
#include "tqueue.h"
#include "tjobstream.h"

class TProc
{
private:

	int tactsWork;  // занятость процессора(такты работы)
	int tactsFree; // простой

public:
	TProc();
	int GetWorkTacts(); // количество тактов работы
	int GetFreeTacts(); // количество тактов простоя
	void SetBusy(TQueue &queue); //проверка(установка) занятости
};