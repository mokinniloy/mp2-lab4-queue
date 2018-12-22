#pragma once

class TJobStream 
{
private:
	double q1; // inensity (new task is generated one time per 1/q1 clocks) 
	int IdentificatorOfTask;
public:
	TJobStream(double _q1);
	bool IsThereNewTask(double RandomValue);
	int RegisterNewTask(); // return IdentificatorOfTask
	int GetQuantityOfAllGeneratedTasks();
};