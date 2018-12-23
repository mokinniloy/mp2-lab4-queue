#include "tproc.h"
#include <stdexcept>

TProc::TProc() : urd(0.0, 1.0)
{
	std::random_device rd;
	dre = std::default_random_engine(rd());
	performance = generate();
}

TProc::TProc(double performance) : urd(0.0, 1.0)
{
	std::random_device rd;
	dre = std::default_random_engine(rd());
	if (performance < 0 || performance > 1)
		throw std::invalid_argument("EXCEPTION: Performance is out of range [0.0, 1.0]");
	this->performance = performance;
}