#pragma once
class TJobStream
{
private:
	double probEndTask; // Вероятность того что задание появится
	int cyclesOnTask; // циклов на задачу
public:
	TJobStream();
	TJobStream(const TJobStream& b);
	TJobStream(double probability);
	bool GenerateTask();
	TJobStream& operator=(const TJobStream&b);
	double GetProbEndTask() { return probEndTask; }
	int GetCyclesOnTask() { return cyclesOnTask; }
	void SetCyclesOnTask(int clocks) { cyclesOnTask = clocks; }
};