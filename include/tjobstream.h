#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

#include<cstdlib>
//#include <vector>
#include<list>
//#include "tqueue.h"

class TJobStream
{
private:
  float q1;
  std::list<int> tasks;
  float get_rand_probability();
  int get_rand_index();
public:
  TJobStream(float q1);
  int look_for_task();
  void complete_task(int id);
};

#endif