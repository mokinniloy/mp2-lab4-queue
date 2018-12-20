#ifndef __JOBSTREAM_H__
#define __JOBSTREAM_H__

#include <list>
#include <random>

#define JobStNoTask -1

class TJobStream
{
private:
  std::mt19937 rng;
  float q1;
  std::list<int> tasks;
  float get_rand_probability();
  int get_rand_index();
  static std::uniform_real_distribution<float> dist_0_1;
public:
  TJobStream(float q1);
  int get_task();
  void complete_task(int id);
};

#endif
