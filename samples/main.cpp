#include <iostream>
#include "tjobstream.h"
#include "tproc.h"
#include "tqueue.h"

void imitation_compute(int N, double q_job, double q_pr, int size)
{
	int clocks = N;
	TJobStream JobStream(q_job);
	TProc Proc(q_pr);
	TQueue Queue(size);

	int clocks_in_waiting = 0;
	int generated_tasks = 0;
	int completed_tasks = 0;
	int skipped_tasks = 0;

	int current_task = 0;

	for (int i = 0; i < clocks; i++)
	{
		current_task = JobStream.generate();
		if (current_task != -1)
		{
			++generated_tasks;
			if (Queue.IsFull())
				++skipped_tasks;
			else
				Queue.Put(current_task);
		}

		if (Proc.in_process())
		{
			if (Proc.end_processing())
			{
				++completed_tasks;
				Proc.set_process(false);
			}
		}

		if (!Proc.in_process())
		{
			if (!Queue.IsEmpty())
			{
				Queue.Get();
				Proc.set_process(true);
			}
			else
				++clocks_in_waiting;
		}
	}

	cout << "Generated tasks " << generated_tasks << endl;
	cout << "Average clocks on task " << (double(clocks - clocks_in_waiting) / double(completed_tasks)) << endl;
	cout << "Skipped tasks " << (double(skipped_tasks)/double(generated_tasks))*100 << "%" << endl;
	cout << "Clocks in waiting " << (double(clocks_in_waiting)/double(clocks)) << "%" << endl;
}



int main()
{
	imitation_compute(100, 0.5, 0.5, 5);

	return 0;
}