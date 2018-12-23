#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

class TJobStream
{
public:

	double q1;
	int jobNum = 1;

	TJobStream(double q = 0.5);
	bool NewJob();
	int GetNum();


};

#endif