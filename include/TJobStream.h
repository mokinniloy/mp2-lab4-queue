#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

#include "tqueue.h"

class TJobStream: public TQueue
{

protected:
	double m_q1; //вероятность появления нового задания (0 <= q1 <= 1)
public:
	int m_ID;
	int m_CountFail;  //количество отказов в обслуживании заданий

	TJobStream(double q1, int size = DefMemSize) : m_q1(q1), TQueue(size)
	{
		m_ID = 0;
		m_CountFail = 0;
	}
	void TactStream();
};

#endif