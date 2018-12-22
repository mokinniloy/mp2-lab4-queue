#include <ctime>
#include <iostream>
#include <cstdlib>
#include "tstack.h"
#include "tqueue.h"
#include "TJobStream.h"
#include "TProc.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int countOfTacts = 0;
	int sizeOfQueue = 0;
	int countOfDenied = 0;
	int countOfAccept = 0;
	double tasksBound;
	double executionBound;

	//----------------------------------------------------

	cout << "Ввидите кол-во тактов: ";
	cin >> countOfTacts;
	cout << "Введите размер очереди : ";
	cin >> sizeOfQueue;
	cout << "Введите верхнюю границу для генерации задачи ( например 10% это 0.1 ) : ";
	cin >> tasksBound;
	cout << "Введите границу для генерации выполнения задачи ( например 10% это 0.1 ) : ";
	cin >> executionBound;
	cout << "\n\n----------------------------------------------\n\n";

	//----------------------------------------------------

	TQueue queue(sizeOfQueue);
	TJobStream tasks(tasksBound , executionBound);
	TProc tacts;

	//----------------------------------------------------

	while ((tacts.GetCountOfFreeTacts() + tacts.GetCountOfWorkTacts()) != countOfTacts)		//имтация работы
	{

		if (tasks.taskGeneration() != 0)
		{
			if(queue.IsFull())
				countOfDenied++;
			else
				queue.Put(tasks.getTaskIndex());
		}

		tacts.BusynessOfProc(queue);

		if (!queue.IsEmpty() && tasks.taskWork() == 1)
		{
			countOfAccept++;
			queue.Get();
		}
	}

	while (!queue.IsEmpty())				
	{
		countOfDenied++;
		queue.Get();
	}
	

	cout << "Всего тактов: " << tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts() << endl;
	cout << "Рабочих тактов: " << tacts.GetCountOfWorkTacts() << endl;
	cout << "Свободных тактов: " << tacts.GetCountOfFreeTacts() << endl;
	cout << "Без тактов: " << (tacts.GetCountOfFreeTacts() * 100 /
		(tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts()))<< "%" << endl;
	cout << "Среднее кол-во тактов выполненных задач: " << (tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts())
		/(countOfAccept) << endl;

	cout << "\n\n----------------------------------------------\n\n";

	cout << "Количество всех задач: " << tasks.getTaskIndex() << endl;
	cout << "Отмененные задачи: " << countOfDenied << endl;
	cout << "Принятые задачи: " << countOfAccept << endl;
	cout << "Процент отказов: " << countOfDenied * 100 / tasks.getTaskIndex() << "%" << endl;

	cout << "\n\n----------------------------------------------\n\n";

}

