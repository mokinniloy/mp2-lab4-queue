#include "tproc.h"
#include "tjobstream.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void emulate(float q1, float q2, int n);

int main()
{
  emulate(1, 0, 0);
  return 0;
}

void emulate(float q1, float q2, int n, size_t clock_count)
{
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
    //выполняем такт процессора, и получаем задачу
    completed_id = proc.clock(),
    task_id      = jobstream.get_task();

    if(completed_id == ProcNotBusy)      //если процессор простаивает
      downtime++;
    else if(completed != ProcBusy)       //если процессор завершил выполнение задачи
    {
      completed++;
      jstream.complete_task(completed_id);
    }

    if(task_id != JobStNoTask)           //если есть доступная задача
      if(!proc.add_task(task_id))       //если очередь задач переполнена
      {
        refused++;
        jstream.complete_task(task_id);
      }
  }
}