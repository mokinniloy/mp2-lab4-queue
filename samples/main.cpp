#include "tqueue.h"
#include "TProc.h"
#include <ctime>
using namespace std;


void test(int qsize,double q1,double q2,int tacts)
{
	int num, count = 0, ref = 0, ok = 0, downtime = 0;
	TQueue q(qsize);
	TJobStream js(q1);
	TProc pr(q2);
	int p1 = (1 / js.GetQ1()), p2 = (1 / pr.GetQ2());

	for (int i = 0, t1 = 0, t2 = 0; i < tacts; i++, t1++, t2++)
	{
		if (t1%p1 == 0)
		{
			num = js.GetNewJob();
			if (num != 0)
			{
				count++;
				q.Put(num);
				if (q.GetRetCode() == DataFull) ref++;
			}
		}

		if (t2%p2 == 0)
		{
			if (!pr.IsProcBusy())
			{
				q.Get();
				if (q.GetRetCode() == DataEmpty) downtime++;
				else ok++;
			}
		}

	}

	setlocale(LC_ALL, "Russian");
	cout << "Ќачальные данные:" << endl;
	cout << "»нтенсивность потока заданий = " << q1 << endl;
	cout << "ѕроизводительность процессора вычислительной системы = " << q2 << endl;
	cout << "–азмер очереди ожидани€ = " << qsize << endl;
	cout << "ќбщее число тактов работы процессора = " << tacts << endl << endl;
	cout << "¬ыходные данные:" << endl;
	cout << " оличество поступивших в вычислительную систему заданий в течение всего процесса имитации = " << count << endl;
	cout << "ќбщее количество выполненных заданий = " << ok<<endl;
	cout << " оличество отказов в обслуживании заданий из-за переполнени€ очереди = " << (double)ref / count * 100 << "%" << endl;
	cout << " оличество тактов просто€ процессора из-за отсутстви€ в очереди заданий дл€ обслуживани€ = " << ((double)downtime / tacts) * 100 << "%" <<endl<<endl<<endl;
}

int main()
{
	srand(time(0));

	int size = 10; //размер очереди ожидани€
	int t = 1000; //общее число тактов работы процессора
	double q = 0.5; //интенсивность потока заданий
	double Q = 0.5; //производительность процессора вычислительной системы
	test(size, q, Q, t);

	q = 0.5; Q = 0.2;
	test(size, q, Q, t);

	q = 0.2; Q = 0.5;
	test(size, q, Q, t);

	return 0;
}