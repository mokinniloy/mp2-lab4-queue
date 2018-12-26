#include <iostream>
#include "tproc.h"

using namespace std;

int main()
{
	int l;

	float q1;
	float q2;
	int tactNum;
	
	setlocale(LC_ALL, "Russian");
	cout << "Пожалуйста, укажите длинну очереди ";
	cin >> l;
	cout << endl;

	TProc proc(l);

	while (true)
	{
		cout << "Пожалуйста, введите q1 ";
		cin >> q1;
		cout << endl;

		cout << "Пожалуйста, введите q2 ";
		cin >> q2;
		cout << endl;

		cout << "Пожалуйста, введите количество тактов симуляции ";
		cin >> tactNum;
		cout << endl<<endl;

		proc.CPUSim(q1 ,q2 ,tactNum );
	}
}



