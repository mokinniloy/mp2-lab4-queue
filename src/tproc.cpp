#include <stdio.h>
#include <iostream>
#include <random>
#include <time.h>
#include <chrono>

#include "tproc.h"

TProc :: TProc (double Rate) {
	if ((Rate>=0)&&(Rate<1)) ProcRate = Rate;
	else throw -1;
	Busy = 0;
}

 int TProc :: IsProcBusy(void) { // процессор занят?
	 return Busy;
 }


 int TProc :: RunNewJob (int JobId) { // приступить к выполнению нового задания
	TProc::JobId = JobId; 
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_real_distribution<double> distribution (0.0,1.0);
	double dist = distribution(generator);
	if (dist<ProcRate)
		return 1;
	else 
		return 0;
 }

 void TProc :: SetBusy (bool status) {
	 Busy = status;
 }
