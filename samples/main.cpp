#include <iostream>
#include <time.h>
#include "TProc.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	TProc proc(0.1, 0.05, 20, 10000);
	proc.ProcWork();
	proc.PrintInfo();
}