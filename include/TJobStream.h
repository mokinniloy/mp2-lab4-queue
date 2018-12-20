class TJobStream
{
private:
	double q1;
public:
	TJobStream(double Intens);
	int GetNewJob(void);
	double GetQ1();
};

double DoubleRand(double max, double min);