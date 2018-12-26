//main.cpp
#include <iostream>
#include "tqueue.h"
#include"TJobStream.h"
#include "TProc.h"

using namespace std;

void chaos(double q1, double q2, int size, int N)
{
	TQueue queue(size);

	int all_tasks = 0;///
	int done_tasks = 0;///
	int refuse = 0;///
	int empty_tacts = 0;///
	int middle_tacts = 0;
	TJobStream stream(q1);
	TProc Pentium(q2);
	//ну че народ погнали нахуй

	for (int i = 0; i < N; ++i)
	{
		int current_task = stream.generate();
		int proc = Pentium.tact(); 

		if (current_task != -1)
		{
			++all_tasks;
			if (queue.IsFull()) 
				refuse++;
			else 
				queue.Put(current_task);
		}
		if (proc==0) {
			if (queue.IsEmpty())
			{
				empty_tacts++;
				Pentium.set_busy(false);
			}
			else 
			{ 
				queue.Get();
				done_tasks++;
				Pentium.set_busy(true);
			}
		}
		if ((proc == 1)&&(!Pentium.get_busy())) 
		{
			done_tasks++;
		}
	}
	cout << "Statistic:  " << endl;
	cout << "All tasks:  " << all_tasks << endl;
	cout << "Done tasks:  " << done_tasks <<" ("<< ((double)done_tasks / all_tasks) * 100 << "%) " << endl;
	cout << "Empty tacts:  " << empty_tacts << " (" << ((double)empty_tacts / N) * 100 << "%) " << endl;
	cout << "Refuse:  " << refuse << " (" << ((double)refuse / all_tasks) * 100 << "%) " << endl;
	cout << "Middle:  " << (double)done_tasks / N << endl;
}

int main() {

	chaos(0.9, 0.5, 3, 200);

	system("pause");
	return 0;
}