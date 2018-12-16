#include<iostream>
#include<cstdlib>
#include<ctime>
#include"../include/tstatistic.h"
using namespace std;
int main()
{
	srand(time(NULL));
	cout << "Testing:" << endl;
	int amountOfClocksOfTest = 1000000;
	int clockFrequencyMhz = 2000;
	TJobStream task(0.5);
	TStatistic::GetStatistic(amountOfClocksOfTest, clockFrequencyMhz, task, 8, 2);
	return 0;
}