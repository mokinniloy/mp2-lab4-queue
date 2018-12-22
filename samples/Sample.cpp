#include <iostream>
#include "TJobStream.h"
#include "TProc.h"
#include "TQueue.h"

void imitate_processor(int N, double q_jobstrm, double q_proc, int que_size)
{
	int clocks = N;
	TJobStream JobStream(q_jobstrm);
	TProc Proc(q_proc);
	TQueue Queue(que_size);

	int downtime = 0;
	int refused_tasks = 0;	
	int generated_tasks = 0;
	int completed_tasks = 0;	

	int current_task = 0;

	for (int i = 0; i < clocks; i++)
	{
		current_task = JobStream.Generate();
		if (current_task != 0)
		{
			++generated_tasks;
			if (Queue.IsFull())	
				++refused_tasks;
			else 
				Queue.Put(current_task);
		}

		if (Proc.in_process())
		{
			if (Proc.end_process())
			{
				++completed_tasks;
				Proc.set_process(false);
			}
		}

		if (!Proc.in_process())
		{
			if (Queue.IsEmpty())
				++downtime;
			else
			{
				Queue.Get();
				Proc.set_process(true);
			}
		}
	}

	std::cout << "The number of generated tasks is " << generated_tasks << std::endl;
	std::cout << "Refused tasks form " << (double)((refused_tasks* 100) /generated_tasks ) << "% of the total" << std::endl;
	std::cout << "The number of average clocks on task is " << (double)((clocks - downtime) /completed_tasks) << std::endl;
	std::cout << "Downtime forms " << (double )((downtime *100) / clocks) << "% of the total clocks" << std::endl;
}



int main()
{
	imitate_processor(100, 0.65, 0.5, 5);

	return 0;
}