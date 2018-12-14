#include "TProc.h"
#include <iostream>
using namespace std;
bool Processor::Tact() //Определяет завершится ли текущее задание на данном такте?
{
	double tmp = dist(generator); // получение числа
	//cout << tmp << " " << endl;
	if (tmp <= q2)
		return 1;
	else return 0;
}

bool Processor::GetFlag()
{
	return flag;
}
void Processor::SetFlag(bool t)
{
	flag = t;
}