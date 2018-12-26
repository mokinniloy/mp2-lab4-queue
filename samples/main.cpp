#include "tsystem.hpp"
#include <iostream>

int main()
{
	TSystem simulation;
	int clockCount, queueSize;
	double cpuTreshold;
	double taskTreshold;

	std::cout << "\t CPU Simulation testing. Input technical system info: " << std::endl;
	std::cin >> clockCount >> queueSize >> cpuTreshold >> taskTreshold;

	simulation.simulate(clockCount, queueSize, cpuTreshold, taskTreshold);
	simulation.printResults();

	exit(0);
}