#include<ctime>
#include<cstdlib>
#include "tjobstream.h"

TJobStream::TJobStream()
{
	probEndTask = 0.5;
	cyclesOnTask = 0;
}

TJobStream::TJobStream(const TJobStream & b)
{
	probEndTask = b.probEndTask;
	cyclesOnTask = b.cyclesOnTask;
}

TJobStream::TJobStream(double probability)
{
	if (probability <= 0 || probability > 1)
		throw "Wrong probability";
	probEndTask = probability;
	cyclesOnTask = 0;
}

bool TJobStream::GenerateTask()
{
	if ((((std::rand() % 10) + 1) / 10.0) <= probEndTask) //генерируется число от 0.1 до 1
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
