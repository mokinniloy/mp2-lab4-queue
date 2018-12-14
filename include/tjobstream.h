#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

//#include<cstdlib>
//#include <vector>
#include <list>
//#include "tqueue.h"

#define JobStNoTask -1

class TJobStream
{
private:
  float q1;
  std::list<int> tasks;
  static float get_rand_probability();
  int get_rand_index();
public:
  TJobStream(float q1);
  int get_task();
  void complete_task(int id);
};

#endif
