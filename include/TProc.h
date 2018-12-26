//TProc.h
#include <random>
#include<ctime>

using namespace std;

class TProc {
private:
	double q2;
	mt19937 generator;
	uniform_real_distribution <double> k2;
	bool is_busy;
public:
	TProc(double q);
	int tact();
	bool get_busy()const;
	void set_busy(bool s);
};