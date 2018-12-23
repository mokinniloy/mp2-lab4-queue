#ifndef __TPROC_H__
#define __TPROC_H__
#include <random>
#include <ctime>

class TProc {
private:
	std::mt19937 generator;
	std::uniform_real_distribution <double> dist;
	double probability_upper_bound;
	bool is_busy;
public:
	TProc(double q2);
	int tick();
	bool get_is_busy();
	void set_is_busy(bool statement);
};

#endif // __TPROC_H__