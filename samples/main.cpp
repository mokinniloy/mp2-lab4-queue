#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

using namespace std;

int main()
{
	TJobStream job(0.5);
	TProc pr(0.7);
	TQueue q(5);
	int tact_imitation = 200;
	int idle_tact = 0, busy_tact = 0, all_tasks = 0, completed_tasks = 0, unfinished_tasks = 0;
	for (int tact = 0; tact < tact_imitation; tact++)
	{
		int requst = job.NewRequest();
		int start = !pr.RunRequest(requst);
		int current_task = 0;
		if (!pr.IsFree() && start) 
		{
			pr.SetFree(true);
		}
		if (pr.IsFree() && start) 
		{ 
			if (!q.IsEmpty())
			{
				current_task = requst;
				requst = q.Get();
				pr.SetFree(false);
				completed_tasks++;
				if (current_task > 0) 
				{
					if (!q.IsFull())
						q.Put(current_task);
					all_tasks++;
				}
			}
			else if (requst > 0) 
			{
				pr.SetFree(false);
				completed_tasks++;
				all_tasks++;
			}
		}
		if ((!start) && (requst > 0))
		{
			if (!q.IsFull())
				q.Put(current_task);
			else unfinished_tasks++;
			all_tasks++;
		}
		if (!pr.IsFree())
			busy_tact++;
		else
			idle_tact++;
	}
	while (!q.IsEmpty()) 
	{
		q.Get();
		unfinished_tasks++;
	}
	cout << "Total tasks for " << tact_imitation << " tacts: " << all_tasks << endl;
	cout << "Completed tasks for " << tact_imitation << " tacts: " << completed_tasks << endl;
	cout << "Unfinished tasks for " << tact_imitation << " tacts: " << unfinished_tasks << endl;
	cout << "Idle tacts of " << tact_imitation << " tacts: " << idle_tact << endl;
	cout << "Busy tacts of " << tact_imitation << " tacts: " << busy_tact << endl;

	return 0;
}