#include "tproc.h"

TProc::TProc(int lenght) : TJobStream(lenght)
{
	q2 = 0;
	tactNum = 0;
	completedComNum = 0;
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
	if (IsEmpty())
	{
		idleNum++;
		return false;
	}
	srand(time(NULL));
	if (distribution(generator) < q2)
	{
		Get();
		completedComNum++;
	}
}

void TProc::CPUSim(float m1, float m2,  int tNum)
{
	//unsigned long int current = 0; // флаг/маркер того, что команда выполнелась
	//unsigned long int totalTactToComplete = 0;
	//int tactCount=0;
	//SetQ1(m1);
	//SetQ2(m2);
	//tactNum = tNum;

	//while (tNum != 0)
	//{
	//	TryToAdd(comandToDoNum);
	//	TryToComplete();
	//	if (!IsEmpty())
	//	{
	//		tactCount++;
	//	}
	//	if (current != completedComtNum)
	//	{
	//		current++;
	//		totalTactToComplete += tactCount;
	//		tactCount = 0;
	//	}

	//	tNum--;
	//}
	//averTuctNumToComplete = totalTactToComplete / comandToDoNum;
	//Report();
	
	int totalTactToComplete = 0;
	int count = 1;
	SetQ1(m1);
	SetQ2(m2);
	tactNum = tNum;

	completedComNum = 0; // количество выл=полненых команд
	averTuctNumToComplete = 0; // среднее число тактов дл€ выполнени€
	idleNum = 0; // количество тактов просто€
    failAddNum = 0; // количество отказов
	comandToDoNum = 0;// количество поступивших команд

	while (tNum != 0)
	{
		TryToAdd(comandToDoNum);
		if (TryToComplete())
		{
			totalTactToComplete += count;
			count = 1;
		}
		else
			count++;

		//Report();

		tNum--;
	}
	if (completedComNum != 0)
		averTuctNumToComplete = totalTactToComplete / completedComNum;
	else
		averTuctNumToComplete = tactNum;
	Report();
}

void TProc::Report()
{
	std::cout << " оличество тактов симул€ции: " << tactNum << std::endl;
	std::cout << "¬еро€тность по€влени€ новой команды q1: " << q1 << std::endl;
	std::cout << "¬еро€тность выполнени€ текущей команды q2: " << q2 << std::endl;
	std::cout << "¬сего поступивших команд: " << comandToDoNum << std::endl;
	std::cout << "¬сего отказов: " << (failAddNum*1.0)/comandToDoNum *100<<'%'<< std::endl;
	std::cout << "¬сего просто€: " << (idleNum*1.0)/comandToDoNum*100<<"%" << std::endl;
	std::cout << "—реднее количество тактов на выполнение команды: " << averTuctNumToComplete << std::endl;
}