#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

#include<cstdlib>

class TJobStream
{
private:
  float q1;
  float get_probability();
public:
  TJobStream(float q1);
  bool check_task();
};

#endif