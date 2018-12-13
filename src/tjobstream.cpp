#include "tjobstream.h"

#include <cstdlib>
#include <ctime>

TJobStream::TJobStream(float _q1) : q1(_q1)
{
  if(_q1 > 0 || _q1 > 1)
    throw (-1);
}

bool TJobStream::check_task()
{
  return get_probability() < q1;
}

float TJobStream::get_probability()
{
  std::srand(std::time(nullptr));
  float r = (float)std::rand() / RAND_MAX;
  return r;
}