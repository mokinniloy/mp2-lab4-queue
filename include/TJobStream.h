#pragma once
#include <random>



class TJobStream
{
private:
	double q1;
	//std::mt19937 mt;
	std::default_random_engine mt;// generator
	std::uniform_real_distribution<double> dstrbtshn;
	int task_id;


public:
	TJobStream( double q);
	int Generate();
	
};

