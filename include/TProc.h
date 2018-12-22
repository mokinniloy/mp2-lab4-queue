#pragma once
#include "TQueue.h"
#include <iostream>
using namespace std;

class TProc
{
private:
	double q2; // productivity (each task is served for 1/q2 clocks)
	TQueue ProcessorExpectationQueue;
	bool isFree;
public:
	TProc(double _q2, int _SizeOfQueue);
	~TProc() { cout << "Destructor TProc" << endl; };
	void EnqueueNewTask(int TaskId); // enqueue Processor queue
	void LoadProcessor(); // dequeue Processor queue
	bool IsProcessorExpectationQueueFull();
	bool IsProcessorExpectationQueueEmpty();
	bool IsProcessorFree();
};
