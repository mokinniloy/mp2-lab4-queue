#include "tproc.h"
#include "tjobstream.h"

#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

void emulate(float, float, int, int);
int min(int a, int b);

int main(int argc, const char *args[])
{
  float q1 = 0.5, q2 = 0.5;
  int n = 10;
  size_t tacts = 10;

  switch(argc)
  {
  case 5:
    tacts = atoi(args[4]);
  case 4:
    n = atoi(args[3]);
  case 3:
    q2 = atof(args[2]);
  case 2:
    q1 = atof(args[1]);
  break;
  }

  emulate(q1, q2, n, tacts);

  return 0;
}

void emulate(float q1, float q2, int n, int tacts)
{
  if(q1 < 0 || q1 > 1 || q2 < 0 || q2 > 1 || n < 1 || tacts < 1)
    throw ("main::emulate");

  TJobStream jstream(q1, min(tacts, n) + 2);
  TProc      proc(q2, n);

  unsigned int
    completed = 0,
    refused   = 0,
    downtime  = 0;
  int
    completed_id,
    task_id;

  for(int i = 0; i < tacts; ++i)
  {
    //получаем задачу
    task_id = jstream.get_task();

    if(task_id != JobStNoTask)            //если есть доступная задача
      if(!proc.add_task(task_id))         //если очередь задач переполнена
      {
        refused++;
        jstream.complete_task(task_id);
      }

    //выполняем такт процессора
    completed_id = proc.tact();

    if(completed_id == ProcNotBusy)       //если процессор простаивает
      downtime++;
    else if(completed_id != ProcBusy)     //если процессор завершил выполнение задачи
    {
      completed++;
      jstream.complete_task(completed_id);
    }
  }

  const int w = 10;
  int total_tasks = completed + refused, uptime = tacts - downtime;
  cout << fixed << left << setprecision(2) << setfill(' ');
  cout
    << "completed tasks:          " << setw(w) << completed       <<
      " (" << completed * 100.0f / total_tasks << "%)\n"
    << "refused tasks:            " << setw(w) << refused         <<
      " (" << refused   * 100.0f / total_tasks << "%)\n"
    << "total tasks:              " << total_tasks                << "\n\n"

    << "uptime tacts:             " << setw(w) << uptime          <<
      " (" << uptime    * 100.0f / tacts       << "%)\n"
    << "downtime tacts:           " << setw(w) << downtime        <<
      " (" << downtime  * 100.0f / tacts       << "%)\n"
    << "total tacts:              " << tacts                      << "\n\n"

    << "average tacts per task:   " << (float)tacts / total_tasks << '\n'
    << "complete task chance:     " << q1 * 100                   << "%\n"
    << "get task chance:          " << q2 * 100                   << "%\n"
    << "queue size:               " << n                          << '\n';

  flush(cout);
}

int min(int a, int b)
{
  return a < b ? a : b;
}
