#include "tproc.h"

#include <cstdlib>
#include <ctime>

TProc::TProc(float _q2, int _n) : q2(_q2), n(_n), task_id(-1)
{
  if(_q2 > 1 || _q2 < 0 || _n < 1)
    throw (-1);

  task_queue = new TQueue(_n);

  std::srand(time(nullptr));
}

bool TProc::is_busy()
{
  if(task_id < 0)
    if(task_queue->IsEmpty())
      return false;
    else
      task_id = task_queue->Get();

  if(get_probability() < q2)


  return task_id > -1;
}

int TProc::clock()
{
  if(task_id < 0)
  {
    if(task_queue->IsEmpty())
      return -1;
    else
      task_id = task_queue->Get();
  }
  else
  {
    if(get_probability() < q2)
    {
      int tmp = task_id;
      task_id = -1;
      return tmp;
    }
  }
}

int TProc::get_task()
{
  int tmp = task_id;
  task_id = -1;
  return tmp;
}

bool TProc::give_task(int id)
{
  if(task_queue->IsFull())
    return false;

  task_queue->Put(id);
  return true;
}

void TProc::handle_task(int id)
{

}