#ifndef __PROC_H__
#define __PROC_H__

class TProc {
private:
	double q2;
	bool state; // 1 = free, 0 = busy
public:
	TProc(double q = 0.5);
	bool IsFree();
	bool IsDone();
	void StartJob();
	void EndJob();

};
#endif