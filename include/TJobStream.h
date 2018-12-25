#include "stdlib.h"
#include <random>
#include <ctime>
class Stream
{
private:
	std::mt19937 generator;
	std::uniform_real_distribution <double> dist;
	int count;
	double q1 ;
public:
	Stream(double d) :count(0), q1(d) {
		dist = std::uniform_real_distribution <double>(0, 1);
		generator = std::mt19937(time(0) + 1);
	}
	bool Tact();
	int GetCount();
};