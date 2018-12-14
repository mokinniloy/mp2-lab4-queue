#include "tproc.h"

#include <cstdlib>
#include <random>

TProc::TProc(float _q2, int _n) : q2(_q2), n(_n), task_id(ProcNotBusy)
{
  if(_q2 > 1 || _q2 < 0 || _n < 1)
    throw ("TProc::TProc");

  task_queue = new TQueue(_n);

  std::srand(std::random_device()());
}

int TProc::tact()
{
  if(task_id == ProcNotBusy)         //если проц свободен, то берет задачу из очереди
  {
    if(task_queue->IsEmpty())
      return ProcNotBusy;
    else
      task_id = task_queue->Get();
  }
  
  if(get_probability() < q2)         //если выполнил программу
  {
    int tmp = task_id;
    task_id = ProcNotBusy;           //отметить, что не занят
    return tmp;                      //вернуть id задачи
  }
  else                               //если выполняет задачу
    return ProcBusy;                 //вернуть ЗАНЯТ
}

bool TProc::add_task(int id)
{
  if(id < 0)
    throw ("TProc::add_task");

  if(task_queue->IsFull())  //если очередь переполнена
    return false;           //вернуть 0

  task_queue->Put(id);      //если в очереди есть место - добавить туда новую задачу
  return true;              //и вернуть 1
}

float TProc::get_probability()
{
  return (float)std::rand() / RAND_MAX;
}
