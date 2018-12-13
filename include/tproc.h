#ifndef __PROC_H__
#define __PROC_H__

#include "tqueue.h"

class TProc
{
private:
  TQueue *task_queue;
  float q2;
  int n;
  int task_id;
  float get_probability();
public:
  TProc(float q2, int n);
  ~TProc(){delete task_queue;}
  bool is_busy();
  int clock();
  int get_task();
  bool give_task(int id);
  void handle_task(int id);
};

#endif