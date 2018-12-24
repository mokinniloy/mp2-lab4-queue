#include <stdio.h>
#include <iostream>
#include <random>
#include <time.h>
#include <chrono>

class TProc
{
private:
	double Productivity;
	int Ti;
	bool Free;
public:
	TProc(double p);
	~TProc() {}
	int RunRequest(int Val);
	bool IsFree() { return Free; }
	void SetFree(bool Val) { Free = Val; }
};