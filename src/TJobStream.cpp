#include "../include/tjobstream.h"
#include <stdexcept>

TJobStream::TJobStream() : dre(time(nullptr)), urd(0.0, 1.0)
{
	intensity = generate();
}

TJobStream::TJobStream(double intensity) : dre(time(nullptr)), urd(0.0, 1.0)
{
	if (intensity < 0 || intensity > 1) 
		throw std::out_of_range("EXCEPTION: Intensity is out of range [0.0, 1.0]");
	this->intensity = intensity;
}