#include "tjobstream.h"

TJobStream::TJobStream(double i)
{
	if (i < 0 || i > 1) throw - 1;
	Intensity = i;
}

int TJobStream::NewRequest()
{
	unsigned s = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(s);
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	double dist = distribution(generator);
	if (dist < Intensity)
		return (rand() % 10000 + 1);
	else
		return 0;
}