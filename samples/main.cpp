#include <iostream>

#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

using namespace std;

void imitation(double q1, double q2, int size, int num_tacts)
{
	TProc proc(q1);
	TJobStream stream(q2);
	TQueue queue(size);
	
	int tasks_completed = 0; // Число решенных задач
	int refusing = 0; // Число отказов в обслуживании
	int downtime = 0; // Количество тактов простоя

	for (int i = 0; i < num_tacts; ++i)
	{
		if (stream.GetNewTask()) // Если сгенерировали новое задание
		{
			if (!queue.IsFull()) // Если очередь не заполнена
			{
				queue.Put(stream.GetTaskNum()); // То кладём номер сгенерированного задания в очередь
			}
			else // Иначе отказываем в обслуживании
			{
				refusing++;
			}
		}

		if (!proc.IsReady()) // Если процессор решает задачу
		{
			if (proc.SolveTask()) // Решит ли он её на этом такте?
			{
				proc.ComplitedTask(); // Процессор освобождается
				tasks_completed++; // Задача решена
			}
		}
		if (proc.IsReady()) // Если процессор свободен
		{
			if (!queue.IsEmpty()) // Если на очереди есть задание
			{
				proc.TakeNewTask(); // Берем эту задачу на выполнение
				queue.Get(); // Освобождаем место в очереди
			}
			else // Если же очередь пуста, то процессор на этом такте простаивает
			{
				downtime++;
			}
		}
	}

	/*
	if (!proc.IsReady()) // Если после num_tacts тактов у процессора осталась задача
	{
		refusing++; // То считаем её отклонённой
	}
	*/

	// Вывод информации о работе процессора

	cout << "Number of completed tasks: " << tasks_completed << ";" << endl;
	cout << "Refusing percentage: " << double(refusing) * 100.0 / double(stream.GetTaskNum()) << "%;" << endl;
	cout << "Average number of tacts: " << double(num_tacts - downtime) / double(tasks_completed) << ";" << endl;
	cout << "Downtime percentage: " << double(downtime) * 100.0 / double(num_tacts) << "%." << endl;
}

int main()
{
	imitation(0.2, 0.6, 50, 500);

	return 0;
}