#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>

#include "tjobstream.h"


TJobStream :: TJobStream (double IntIns) {
	if ((IntIns>=0)&&(IntIns<1))
		JobIntIns = IntIns;
	else throw -1;
}
 int TJobStream :: GetNewJob() { 
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_real_distribution<double> distribution (0.0,1.0);
	double dist = distribution(generator);
	if (dist<JobIntIns)			
		return (rand() % 10000 + 1);
	else 
		return 0;
 }
