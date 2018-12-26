#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

using namespace std;

int main () {
	TJobStream job (0.2);
    TProc proc (0.5);
    TQueue q (3);
	int tact_imitation = 100;
	int idle_tact = 0, busy_tact = 0, all_tasks = 0, completed_tasks = 0, unfinished_tasks = 0;
	for (int tact = 0; tact < tact_imitation; tact ++)
	{
		int task = job.GetNewJob(); //получает id задачи
		int start = proc.RunNewJob(task); //процессор может выполнить
		int current_task = 0;

		if ((proc.IsProcBusy())&&(start)) { //процессор готов и занят
			proc.SetBusy(false);
		}
		if ((!proc.IsProcBusy())&&(start)) { //процессор готов и не занят
			if (!q.IsEmpty())
			{
				current_task = task; //запоминаем текущую задачу
				task = q.Get(); //забираем из очереди нужную задачу
				proc.SetBusy(true); //процессор занят задачей из очереди
				completed_tasks++; //выполнена еще одна задача
				if (current_task > 0) { 
					if (!q.IsFull()) 
						q.Put(current_task);
					all_tasks++;
				}
			}
			else if (task>0) { //если очередь пуста, но задача существует
				proc.SetBusy(true); //процессор занят этой задачей
				completed_tasks++; //выполнена еще одна задача
				all_tasks++;
			}
		}
		if ((!start)&&(task>0)) {//процессор не готов, но задача есть
			if (!q.IsFull()) 
				q.Put(current_task);
			else unfinished_tasks++;
			all_tasks++;
		}
		if (proc.IsProcBusy()) 
			busy_tact++;
		else 
			idle_tact++;
	}
	while (!q.IsEmpty()) {
		q.Get();
		unfinished_tasks++;
	}
	cout<<"Total tasks for "<<tact_imitation<<" tacts: "<<all_tasks<<endl;
	cout<<"Completed tasks for "<<tact_imitation<<" tacts: "<<completed_tasks<<endl;
	cout<<"Unfinished tasks for "<<tact_imitation<<" tacts: "<<unfinished_tasks<<endl;
	cout<<"Idle tacts of "<<tact_imitation<<" tacts: "<<idle_tact<<endl;
	cout<<"Busy tacts of "<<tact_imitation<<" tacts: "<<busy_tact<<endl;

	return 0;
}