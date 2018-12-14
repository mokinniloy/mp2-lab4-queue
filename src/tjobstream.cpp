#include "tjobstream.h"

#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>

TJobStream::TJobStream(float _q1) : q1(_q1)
{
  if(_q1 < 0 || _q1 > 1)
    throw (-1);

  for(int i = 0; i < 16; ++i)
    tasks.push_back(i);

  std::srand(std::time(nullptr));
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
    throw (-2);

  tasks.push_back(id);
}

float TJobStream::get_rand_probability()
{
  float r = (float)std::rand() / RAND_MAX;
  return r;
}

int TJobStream::get_rand_index()
{
  int ind = std::rand() % tasks.size();
  return ind;
}