 #include <random>
  
   using namespace std;
  
   class TProc
  {
  private:
  	double q_task; //Øàíñ âûïîëíåíèÿ çàäà÷è
  	default_random_engine gen;
  	uniform_real_distribution<double> distribution;
  	bool status;
  public:
  	TProc(double q);
  	bool processor_tact();
  	bool get_status();
  	void set_status(bool s);
  };