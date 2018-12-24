#include <stdio.h>
#include <iostream>
#include <random>
#include <chrono>

class TJobStream
{
private:
	double Intensity;

public:
	TJobStream(double i);
	~TJobStream() {}
	int NewRequest();
};