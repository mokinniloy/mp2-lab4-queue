#include<ctime>
#include<cstdlib>
#include "tjobstream.h"

TJobStream::TJobStream()
{
	probEndTask = 0.5;
	cyclesOnTask = 0;
	probAddTask = 0.5;
}

TJobStream::TJobStream(const TJobStream & b)
{
	probEndTask = b.probEndTask;
	probAddTask = b.probAddTask;
	cyclesOnTask = b.cyclesOnTask;
}

TJobStream::TJobStream(double probabilityEnd, double probabilityAdd)
{
	if (probabilityEnd <= 0 || probabilityEnd > 1 || probabilityAdd>1||probabilityAdd<=0)
		throw "Wrong probability";
	probEndTask = probabilityEnd;
	probAddTask = probabilityAdd;
	cyclesOnTask = 0;
}

bool TJobStream::GenerateTask()
{
	if ((((std::rand() % 10) + 1) / 10.0) <= probEndTask) //генерируется число от 0.1 до 1
		return true;
	else
		return false;

}

bool TJobStream::GenerateAddTask()
{
	if ((((std::rand() % 10) + 1) / 10.0) <= probAddTask) //генерируется число от 0.1 до 1
		return true;
	else
		return false;
}

TJobStream & TJobStream::operator=(const TJobStream & b)
{
	if (this != &b)
	{
		probEndTask = b.probEndTask;
		cyclesOnTask = b.cyclesOnTask;
	}
	return *this;
}
