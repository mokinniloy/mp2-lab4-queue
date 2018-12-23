#include <random>
  
   using namespace std;
  
   class TJobStream
  {
  private:
  	double q_min;
  	default_random_engine gen;
  	uniform_real_distribution<double> distribution;
  	int id;
  public:
  	TJobStream(double q);
  	int generate();
  }; 