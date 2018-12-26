#pragma once
class TJobStream
{
private:
	double probEndTask; // ¬еро€тность того что задание завершитс€
	double probAddTask; // ¬еро€тность того что задание по€витс€
	int cyclesOnTask; // циклов на задачу
public:
	TJobStream();
	TJobStream(const TJobStream& b);
	TJobStream(double probabilityEnd, double probabilityAdd);
	bool GenerateTask();
	bool GenerateAddTask();
	TJobStream& operator=(const TJobStream&b);
	double GetProbEndTask() { return probEndTask; }
	int GetCyclesOnTask() { return cyclesOnTask; }
	void SetCyclesOnTask(int clocks) { cyclesOnTask = clocks; }
};