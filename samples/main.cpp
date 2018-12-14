#include "tproc.h"
#include "tjobstream.h"

#include <iostream>
#include <cstdlib>
#include <locale>

using namespace std;

void emulate(float, float, int, size_t);

int main(int argc, const char *args[])
{
  float q1 = 0.5, q2 = 0.5;
  int n = 10;
  size_t clocks = 10;
  
  switch(argc)
  {
    case 5:
      clocks = (size_t)atoi(args[4]);
    case 4:
      n = atoi(args[3]);
    case 3:
      q2 = atof(args[2]);
    case 2:
      q1 = atof(args[1]);
      emulate(q1, q2, n, clocks);
      return 0;
    break;
  }

  return 0;
}

void emulate(float q1, float q2, int n, size_t clock_count)
{
  if(q1 < 0 || q1 > 1 || q2 < 0 || q2 > 1 || n < 1)
    throw ("main::emulate");

  TJobStream jstream(q1);
  TProc      proc(q2, n);

  size_t
    completed = 0,
    refused   = 0,
    downtime  = 0;
  int
    completed_id,
    task_id;

  for(size_t i = 0; i < clock_count; ++i)
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
    completed_id = proc.clock();

    if(completed_id == ProcNotBusy)       //если процессор простаивает
      downtime++;
    else if(completed_id != ProcBusy)     //если процессор завершил выполнение задачи
    {
      completed++;
      jstream.complete_task(completed_id);
    }
  }

  cout
    << "completed tasks: " << completed   << '\n'
    << "refused tasks:   " << refused     << '\n'
    << "downtime clocks: " << downtime    << '\n'
    << "q1:              " << q1          << '\n'
    << "q2:              " << q2          << '\n'
    << "queue size:      " << n           << '\n'
    << "total clocks:    " << clock_count << '\n';

  flush(cout);
}