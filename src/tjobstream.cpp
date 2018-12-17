#include "tjobstream.h"

#include <iterator>
#include <algorithm>

TJobStream::TJobStream(float _q1) : q1(_q1)
{
  if(_q1 < 0 || _q1 > 1)
    throw ("TJobStream::TJobStream");

  for(int i = 0; i < 256; ++i)
    tasks.push_back(i);

  rng = std::mt19937(std::random_device()());
}

int TJobStream::get_task()
{
  if(get_rand_probability() < q1)
  {
    int i = get_rand_index();
    std::list<int>::iterator itr = tasks.begin();
    std::next(itr, i);

    int id = *itr;

    tasks.erase(itr);

    return id;
  }

  return JobStNoTask;
}

void TJobStream::complete_task(int id)
{
  if(std::find(tasks.begin(), tasks.end(), id) != tasks.end())
  {
    throw ("TJobStream::complete_task");
  }

  tasks.push_back(id);
}

float TJobStream::get_rand_probability()
{
  return dist_0_1(rng);
}

int TJobStream::get_rand_index()
{
  std::uniform_int_distribution<int> dst(0, tasks.size());
  return dst(rng);
}

std::uniform_real_distribution<float> TJobStream::dist_0_1 = std::uniform_real_distribution<float>(0.0f, 1.0f);
