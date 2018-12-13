#include "tproc.h"
#include "tjobstream.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void emulate(float q1, float q2, int n);

int main()
{
  emulate(1, 0, 0);
  return 0;
}

void emulate(float q1, float q2, int n)
{
  TJobStream jstream(q1);
  flush(cout);
}