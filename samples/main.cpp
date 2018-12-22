#include <iostream>
#include <time.h>
#include "tproc.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	TProc proc(0.1, 0.05, 20, 10000);
	proc.ProcWork();
	proc.PrintInfo();
}