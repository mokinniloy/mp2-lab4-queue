#include <iostream>
#include "tqueue.h"
#include "tproc.h"
#include "tjobstream.h"

using namespace std;

void imitation(int q_size, int q_tacts, double q_min, double q_task)
{
	TQueue queue(q_size);
	TJobStream stream(q_min);
	TProc proc(q_task);
	int task = 0;
	int proc_result = 0;
	int count_tasks = 0;
	int err = 0;
	int complete_tasks = 0;
	int empty_tacts = 0;
	for (int i = 0; i < q_tacts; i++)
	{
		task = stream.generate();
		proc_result = proc.processor_tact();
		if (task != -1)
		{
			count_tasks++;
			if (!queue.IsFull())
				queue.Put(task);
			else err++;
		}
		if (proc_result == 1)
		{
			if (!queue.IsEmpty())
			{
				queue.Get();
				complete_tasks++;
				proc.set_status(true);
			}
			else 
			{
				empty_tacts++;
				proc.set_status(false);
			}
		}
		if ((proc_result == 0) && (!proc.get_status()))
		{
			complete_tasks++;
		}
	}
	cout << "Results :" << endl;
	cout << "Count tasks: " << count_tasks << endl;
	cout << "Complete tasks : " << ((double)complete_tasks / q_tacts) * 100 << "%" << endl;
	cout << "Empty tacts : " << ((double)empty_tacts / q_tacts) * 100 << "%" << endl;
	cout << "Errors : " << ((double)err / q_tacts) * 100 << "%" << endl;
}

int main()
{
	imitation(25, 150, 0.5, 0.8);
	system("pause");
	return 0;
}
