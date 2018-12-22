//#include "TQueue.h"
//#include "TProc.h"
//#include "TJobStream.h"
#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TJobStream.h"
#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TProc.h"
//#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


double GetRandomValue() // return random double value between 0...1
{
	return (double)(rand()) / RAND_MAX;
}

void Simulate(double _q1, double _q2, int _SizeOfQueue, int _clocks)
{
	TProc processor(_q1, _SizeOfQueue);
	TJobStream jobstream(_q2);

	int QuantityOfAllGeneratedTasks = 0; // by jobstream. it is the same as IdentificatorOfTask
	int QuantityOfRejections = 0; // when Processor queue was full
	int QuantityOfIdleClocks = 0; // when Processor queue was empty
	double Productivity = 1 / _q2;


	for (int i = 0; i < _clocks; i++)
	{
		if (jobstream.IsThereNewTask(GetRandomValue()))
		{
			if (!processor.IsProcessorExpectationQueueFull())
			{
				processor.EnqueueNewTask(jobstream.RegisterNewTask());
				QuantityOfAllGeneratedTasks++;
			}
			else
				QuantityOfRejections++;
		}

		if (processor.IsProcessorFree(GetRandomValue()))
		{
			if (!processor.IsProcessorExpectationQueueEmpty())
			{
				processor.LoadProcessor();
			}
			else
				QuantityOfIdleClocks++;
		}

	}


	cout << "=====Results=====" << endl;
	cout << "Initial parameters of simulation: " << endl;
	cout << "Intensity of JobStream = " << 1 / _q1 << " (q1 = " << _q1 << "), q2 = " << _q2 << ", SizeOfQueue = " << _SizeOfQueue << ", Clocks = " << _clocks << endl;
	QuantityOfAllGeneratedTasks = jobstream.GetQuantityOfAllGeneratedTasks();
	cout << "QuantityOfAllGeneratedTasks = " << QuantityOfAllGeneratedTasks << endl;
	cout << "QuantityOfRejections = " << QuantityOfRejections << endl;
	cout << "QuantityOfIdleClocks = " << QuantityOfIdleClocks << endl;
	cout << "Productivity (clocks per task) = " << Productivity << endl;
	cout << "=================" << endl;
	cout << endl;
}

int main()
{
	srand(time(0));
    /*for (int i = 0; i < 10; i++)
    {
        cout << GetRandomValue() << endl;
    }
	*/
	Simulate(0.5, 0.5, 10, 100);

	system("pause");
	return 0;
}
