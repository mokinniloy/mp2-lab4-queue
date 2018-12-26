#pragma once
#include <random>

class TProc
{
	double q2;
	//std::mt19937 mt;
	std::default_random_engine mt;// generator
	std::uniform_real_distribution<double> dstrbtshn;
	bool process;
public:
	TProc( double q);
	void set_process(bool s) {  process = s; }
	bool in_process() { return process; }
	bool end_process(); 

};

