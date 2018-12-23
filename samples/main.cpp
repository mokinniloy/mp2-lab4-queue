#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"


using namespace std;

int main()
{
	int tactNum = 100, qSize = 10;
	double q1 = 0.5, q2 = 0.3 ;
	
	TJobStream w(q1);
	TProc p(q2);
	TQueue q(qSize);
	int Alltasks = 0;
	int DoneTasks = 0;
	int NotFitJobs = 0;
	int DownT = 0;
	int UnprocessedTask = 0;
	

	for (int i = 0; i < tactNum; i++){
		if (w.NewJob())	{
			Alltasks++;
		if (q.IsFull()){
				NotFitJobs++;
			}

		else{
				q.Put(w.GetNum());
			}
		}

		if (p.IsFree())
		{
		if (q.IsEmpty())
		{
				DownT++;
	}
		else{
				q.Get();
				p.StartJob();
			}
		}
		
		else{
			if (p.IsDone())
			{
				p.EndJob();
				DoneTasks++;
			if (q.IsEmpty())
					DownT++;
			else
				{
					q.Get();
					p.StartJob();
				}
			}
		}
	}
	while (!q.IsEmpty()){
		UnprocessedTask++;
		q.Get();
	}

	cout << "All jobs: " << Alltasks << endl;
	cout << "Jobs Completed: " << DoneTasks << ", that is " << ((double)DoneTasks / (double)Alltasks) * 100 << "%" << endl;
	
	cout << "Jobs rejected: " << NotFitJobs << ", that is " << (double)NotFitJobs / (double)Alltasks * 100 << "%" << endl;
	cout << "Jobs unprocessed:" << UnprocessedTask << ", that is " << (double)UnprocessedTask / (double)Alltasks * 100 << "%" << endl;
	
	cout << "Time for 1 job:" << (double)tactNum / (double)DoneTasks << " tacts" << endl;
	cout << "Processor downtime:" << DownT << ", that is " << (double)DownT / (double)tactNum * 100 << "%" << endl;

	return 0;
}