#include <random>

using namespace std;

class TJobStream
{
private:
	double q1;
	default_random_engine generator;
	uniform_real_distribution<double> distribution;
	int task_id;
public:
	TJobStream(double q);
	int generate();
};