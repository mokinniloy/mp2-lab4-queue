 #ifndef __PROC_H__
  #define __PROC_H__
  
   #include <random>
  #include <ctime>
  
   class TProc {
      double q2;
      std::mt19937 mt;
      std::uniform_real_distribution<double> rand;
      bool Empty;
  public:
      TProc();
      bool IsComplete();
      bool IsEmpty();
      bool IsReady();
      void Ready();
      void Busy();
  };
  
   #endif // __PROC_H__