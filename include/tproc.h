#include "tjobstream.h"
#include <stdlib.h>
#include <random>
#include <iostream>


class  TProc : protected TJobStream
{
protected:
	float q2;
	int tactNum; // êîëè÷åñòâî òàêòîâ
	int completedComNum; // количество выполненых команд
	float averTuctNumToComplete; // ñðåäíåå ÷èñëî òàêòîâ äëÿ âûïîëíåíèÿ
	int idleNum; // êîëè÷åñòâî òàêòîâ ïðîñòîÿ
public:
	TProc(int lenght);
	bool TryToComplete();
	void Report();
	void CPUSim(float m1, float m2, int tNum);
	void SetQ2(float x);
};
