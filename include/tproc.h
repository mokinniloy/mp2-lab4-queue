#include <random>

using namespace std;

class TProc
{
private:
	double q2;
	default_random_engine generator;
	uniform_real_distribution<double> distribution;
	bool process;
public:
	TProc(double q);
	bool end_processing();
	bool in_process();
	void set_process(bool s);
};