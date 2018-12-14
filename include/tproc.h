#ifndef __PROC_H__
#define __PROC_H__

#include "tqueue.h"

#define ProcBusy     -2
#define ProcNotBusy  -1

class TProc
{
private:
  TQueue *task_queue;
  float q2;
  int n;
  int task_id;
  static float get_probability();
public:
  TProc(float q2, int n);
  ~TProc(){delete task_queue;}
  int tact();
  bool add_task(int id);
};

#endif
