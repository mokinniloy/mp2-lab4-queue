#include "tqueue.h"
#include "TProc.h"
#include "TJobStream.h"
#include <iostream>
using namespace std;
void TryOurProcessor(int tacts,int size_q, double q1,double q2)
{
	TQueue q(size_q);
	Processor pr(q2);
	Stream st(q1);
	int generated_tasks = 0;
	int completed_tasks = 0;
	int drop_tasks = 0;
	int free_tacts = 0;
	int tmp = 0;
	int sum = 0;
	for (int i = 0; i < tacts; ++i)
	{
		tmp++;
		bool a = st.Tact();// сгенерированно новое задание или нет
		if (a)
		{
			generated_tasks++;
			if (!q.IsFull()) q.Put(st.GetCount());
			else drop_tasks++;
		}

		bool b = pr.Tact();
		//cout << a << "   " << b << endl;
		if (b) // задание завершилось на текущем такте
		{
			if (pr.GetFlag() == 1)
			{
				completed_tasks++;
				sum += tmp;
			}
			pr.SetFlag(0);

		}

		if (pr.GetFlag()==0)
		{
			if (!q.IsEmpty())
			{
				q.Get();
				pr.SetFlag(1);
				tmp = 0;
			}
			else free_tacts++;
		}
		
	}

	cout << "Total tacts = " << tacts << endl;
	cout << "Free tacts = " << free_tacts << endl;// такты простоя
	cout << "part free_tacts of total tacts = " << (double(free_tacts) / tacts) * 100 << "%" << endl;
	cout << "Generated tasks = " << generated_tasks << endl;
	cout << "Droped tasks = " << drop_tasks<<" Completed tasks = "<<completed_tasks<<endl;// отказов в обслуживании
	cout << "Part drop tasks of generated tasks = "<< (double(drop_tasks) / generated_tasks) * 100 << "%" <<endl;
	cout << "Tacts on 1 task = " << double(sum) / completed_tasks <<" Must be approximately equal(depend on random) = "<<1/q2<<endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	TryOurProcessor(1000,100,0.7,0.5);// Моделирование поступлений заданий в процессор и вывод результатов
	TQueue q;
	int tmp;
	cout << "Тестирование программ поддержки структуры типа данных очередь" << endl;
	for (int i = 0; i < 35; ++i)
	{
		q.Put(i);
		cout << "Положили значение " << i << "  Код " << q.GetRetCode() << endl;
	}
	int k;
	while (!q.IsEmpty())
	{
		tmp = q.Get();
		cout << "Взяли значение " << tmp << "  Код " << q.GetRetCode() << endl;
	}
	return 0;
}
