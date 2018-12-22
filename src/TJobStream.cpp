#include "TJobStream.h"
#include <iostream>

using namespace std;

void TJobStream::TactStream()
{

	double chance = (rand() % 100 / 100.0f);
	if (chance <= m_q1)
	{
		m_ID++;
		if (!IsFull())
			Put(m_ID);
		else
			m_CountFail++;
	}
}