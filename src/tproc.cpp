#include "tproc.h"
  
   TProc::TProc(double q)
  {
  	q_task = q;
  	distribution = uniform_real_distribution<double>(0, 1);
  	status = false;
  }
  
   bool TProc::processor_tact()
  {
  	return (distribution(gen) < q_task);
  }
  
   bool TProc::get_status()
  {
  	return status;
  }
  
   void TProc::set_status(bool s)
  {
  	status = s;
  } 