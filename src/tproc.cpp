#include "tproc.h"

TProc::TProc(int lenght) : TJobStream(lenght)
{
	q2 = 0;
	tactNum = 0;
	completedTactNum = 0;
	averTuctNumToComplete = 0;
}

void TProc::SetQ2(float m2)
{
	if (m2 <= 0 || m2 > 1)
		throw - 1;
	q2 = m2;
}

bool TProc::TryToComplete()
{
	if (!IsEmpty() && pMem != nullptr)
	{
		srand(time(NULL));
		if ((rand() % 100) / (100 * 1.0) < q2)
		{
			completedTactNum++;
			Get();
			return false;
		}
		return false;
	}
	idleNum++;
	return false;
}

void TProc::CPUSim(float m1, float m2, unsigned long int tNum)
{
	unsigned long int current = 0; // флаг/маркер того, что команда выполнелась
	unsigned long int totalTactToComplete = 0;
	int tactCount=0;
	SetQ1(m1);
	SetQ2(m2);
	tactNum = tNum;

	while (tNum != 0)
	{
		TryToAdd(comandToDoNum);
		TryToComplete();
		if (!IsEmpty())
		{
			tactCount++;
		}
		if (current != completedTactNum)
		{
			current++;
			totalTactToComplete += tactCount;
			tactCount = 0;
		}

		tNum--;
	}
	averTuctNumToComplete = totalTactToComplete / comandToDoNum;
	Report();
}

void TProc::Report()
{
	std::cout << "Количество тактов симуляции: " << tactNum << std::endl;
	std::cout << "Вероятность появления новой команды q1: " << q1 << std::endl;
	std::cout << "Вероятность выполнения текущей команды q2: " << q2 << std::endl;
	std::cout << "Всего поступивших команд: " << comandToDoNum << std::endl;
	std::cout << "Всего отказов: " << ((failAddNum/tactNum)*100)/1 << std::endl;
	std::cout << "Всего простоя: " << ((idleNum/tactNum)*100)/1 <<'%'<< std::endl;
	std::cout << "Среднее количество тактов на выполнение команды: " << averTuctNumToComplete << std::endl;
}