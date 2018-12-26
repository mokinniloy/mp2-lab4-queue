#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"


using namespace std;

int main()
{
	int tactNum = 10000;
	double q1 = 0.5;
	double q2 = 0.3;
	int qSize = 100;

	int JobsQuantity = 0;
	int CompletedJobs = 0;
	int NotFitJobs = 0;
	int Downtime = 0;
	int UnprocessedJobs = 0;
	TJobStream j(q1);
	TProc p(q2);	
	TQueue q(qSize);

	for (int i = 0; i < tactNum; i++)
	{
		if (j.NewJob())
		{
			JobsQuantity++;
			if (q.IsFull())
			{
				NotFitJobs++;
			}
			else
			{
				q.Put(j.GetNum());
			}
		}

		if (p.IsFree())
		{
			if (q.IsEmpty())
			{
				Downtime++;
			}
			else
			{
				q.Get();
				p.StartJob();
			}
		}
		else
		{
			if (p.IsDone())
			{
				p.EndJob();
				CompletedJobs++;
				if (q.IsEmpty())
					Downtime++;
				else
				{
					q.Get();
					p.StartJob();
				}
			}
		}
	}
	while (!q.IsEmpty())
	{
		UnprocessedJobs++;
		q.Get();
	}


	cout << "Total Jobs: " << JobsQuantity << endl;
	cout << "Jobs Completed: " << CompletedJobs << ", that is " << ((double)CompletedJobs / (double)JobsQuantity)*100 << "%" << endl;
	cout << "Jobs rejected: " << NotFitJobs << ", that is " << (double)NotFitJobs / (double)JobsQuantity * 100 << "%" << endl;
	cout << "Jobs unprocessed:" << UnprocessedJobs << ", that is " << (double)UnprocessedJobs / (double)JobsQuantity * 100 << "%" << endl;
	cout << "Time for 1 job:" << (double)tactNum/(double)CompletedJobs << " tacts"<< endl;
	cout << "Processor downtime:" << Downtime << ", that is " << (double)Downtime / (double)tactNum * 100<< "%" << endl;
}