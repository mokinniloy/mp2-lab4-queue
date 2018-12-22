#ifndef __PROC_H__
#define __PROC_H__

#include "TJobStream.h"

#define DefMaxTacts 1000
enum ProcStatus { BUSY, FREE };

class TProc
{

protected:
	double m_q2; //вероятность завершения выполнения задания (0 <= q2 <= 1)
	TJobStream m_JobStream;
	int m_CountDowntime;  //количество тактов простоя
	int m_MaxTact;
	ProcStatus m_Status;
public:
	TProc(double q1, double q2, int size, int maxTact = DefMaxTacts) : m_JobStream(q1, size)
	{
		if (q1 < 0 || q1 > 1 || q2 < 0 || q2 > 1 || size < 0 || maxTact < 0)
			throw "DataError";
		m_MaxTact = maxTact;
		m_q2 = q2;
		m_CountDowntime = 0;
		m_Status = FREE;
	}
	void ProcWork();
	void PrintInfo();
};

#endif