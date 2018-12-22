//TJobStream.h
#include <random>
#include<ctime>

using namespace std;

class TJobStream {
	
private:
	double q1;
	mt19937 generator;
	uniform_real_distribution <double> k1;
	int task_id;

public:
	TJobStream(double q);
	int generate();
};