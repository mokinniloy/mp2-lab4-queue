#ifndef __PROC_H__
#define __PROC_H__

#include "tqueue.h"

#include <random>

#define ProcBusy     -2
#define ProcNotBusy  -1

class TProc
{
private:
  TQueue *task_queue;
  std::mt19937 rng;
  float q2;
  int n;
  int task_id;
  float get_probability();
  static std::uniform_real_distribution<float> dist_0_1;
public:
  TProc(float q2, int n);
  ~TProc(){delete task_queue;}
  int tact();
  bool add_task(int id);
};

#endif
