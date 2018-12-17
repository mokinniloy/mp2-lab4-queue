#include "tjobstream.h"



TJobStream::TJobStream(double q1) :task_number(0)
{
	upper_bound = q1;
	generate_value = std::mt19937(time(0) + 1);
}
/*-------------------------------------------------------------*/
int TJobStream::Tact()
{
	if (std::uniform_real_distribution<double> {0, 1} (generate_value) < upper_bound)
		return ++task_number;
	else
		return 0;
}
/*-------------------------------------------------------------*/