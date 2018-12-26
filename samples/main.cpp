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
	srand(time(0));
	int countOfTacts = 0, sizeOfQueue = 0, countOfDenied = 0, countOfAccept = 0;
	double tasksBound , executionBound;

	//----------------------------------------------------

	cout << "write the count of tacts : ";
	cin >> countOfTacts;
	cout << "write the size of queue : ";
	cin >> sizeOfQueue;
	cout << "write the upper bound for generation of tasks ( example 80% it's 0.8 ) : ";
	cin >> tasksBound;
	cout << "write the bound for task execution generation ( example 80% it's 0.8 ) : ";
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
				queue.Put(tasks.getTaskNum());
		}

		tacts.BusynessOfProc(queue);

		if (!queue.IsEmpty() && tasks.taskWork() == 1)
		{
			countOfAccept++;
			queue.Get();
		}
	}

	while (!queue.IsEmpty())				//отклонение в решении оставшихся в очереди нерешенных задач
	{
		countOfDenied++;
		queue.Get();
	}
	//----------------------------------------------------

	cout << "all tacts			 : " << tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts() << endl;
	cout << "tacts work			 : " << tacts.GetCountOfWorkTacts() << endl;
	cout << "tacts free			 : " << tacts.GetCountOfFreeTacts() << endl;
	cout << "persent of tacts free		 : " << (tacts.GetCountOfFreeTacts() * 100 /
		(tacts.GetCountOfWorkTacts() + tacts.GetCountOfFreeTacts()))<< "%" << endl;
	cout << "average count of tasks execution : " << tacts.GetCountOfWorkTacts()
		/(countOfAccept) << endl;

	cout << "\n\n----------------------------------------------\n\n";

	cout << "count of all tasks		 : " << tasks.getTaskNum() << endl;
	cout << "denied tasks			 : " << countOfDenied << endl;
	cout << "accepted tasks			 : " << countOfAccept << endl;
	cout << "persent of denied tasks		 : " << countOfDenied * 100 / tasks.getTaskNum() << "%" << endl;

	cout << "\n\n----------------------------------------------\n\n";

}

