#include "stdlib.h"
#include <random>
#include <ctime>
class Processor
{
private:
	std::mt19937 generator;
	std::uniform_real_distribution <double> dist;
	double q2;// Граница
	bool flag;
public:
	Processor(double q) : q2(q) { flag = 0;
	dist = std::uniform_real_distribution <double>(0, 1);
	generator = std::mt19937(time(0));
	}
	bool Tact();
	bool GetFlag();
	void SetFlag(bool t);
};