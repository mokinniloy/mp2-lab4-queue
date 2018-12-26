#include "tproc.h"
#include<iostream>
TProc::TProc(int clockFrequencyMhz, int clocksTarget, int qSize, int intensivityInOut)
{
	if (clockFrequencyMhz <= 0 || clocksTarget <= 0 || qSize <= 0 || intensivityInOut <= 0)
		throw "wrong data";
	this->clockFrequency = clockFrequencyMhz;
	this->clocksTarget = clocksTarget;
	this->qSize = qSize;
	this->intensivityInOut = intensivityInOut;
	queueIn = new TQueue(qSize);
	queueOut = new TQueue(qSize);
}

TProc::TProc()
{
	clocksTarget = 1000;
	intensivityInOut = 2;
	qSize = 4;
	clockFrequency = DEFAULT_FREQUENCY;
	queueIn = new TQueue(qSize);
	queueOut = new TQueue(qSize);
}

TProc::~TProc()
{
	delete queueIn;
	delete queueOut;
}

void TProc::DoClock(TJobStream& b)
{
	int cyclesOfDoTask = clockFrequency / 100;
	for (int i = 0; i < intensivityInOut; i++)
		if (b.GenerateAddTask())
			AddTask(b);
	for (int i = 0; i < cyclesOfDoTask; i++)
		DoTask(b);
	for (int i = 0; (i < intensivityInOut) && (!queueOut->IsEmpty()); i++)
		queueOut->Get();
}

bool TProc::AddTask(TJobStream& b)
{
	if (amountOfClocks >= clocksTarget)
		return false;
	if (!queueIn->IsFull())
	{
		amountOfAddedTask++;
		queueIn->Put(b);
		return true;
	}
	else
	{
		amountIgnoreTask++;
		return false;
	}
}

bool TProc::DoTask(TJobStream & b)
{
	if (amountOfClocks >= clocksTarget)
		return false;
	if (!queueIn->IsEmpty())
	{
		TJobStream temp = b;
			temp = queueIn->Get();
		if (!queueOut->IsFull())
			queueOut->Put(CycleOnTask(temp));
		amountDoneTask++;
		return true;
	}
	else
	{
		clocksOfIdle++;
		amountOfClocks++;
		return false;
	}

}

int TProc::CycleOnTask(TJobStream & b)
{
	int clocks = 0;
	while ((clocks < DEFAULT_FREQUENCY) && (amountOfClocks < clocksTarget))
	{
		clocks++;
		amountOfClocks++;
		if (b.GenerateTask())
			return clocks;
		if (b.GenerateAddTask())
			AddTask(b);
		if (!queueOut->IsEmpty())
			queueOut->Get();
	}
	return clocks;
}
