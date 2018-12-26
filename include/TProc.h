#include "TJobStream.h"

class TProc
{
private:
	double q2;
	int JobId;
public:
	TProc(double Rate);
	int IsProcBusy(void);
	double GetQ2();
};

