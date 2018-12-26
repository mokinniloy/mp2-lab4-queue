#ifndef __TPROC_H__
#define __TPROC_H__

class TProc {
 private:
 double ProcRate; // производительность процессора
 int JobId; // Id выполняемого задания
 int Busy;
 public:
 TProc (double Rate);
 int IsProcBusy(void) ; // процессор занят?
 void SetBusy (bool status);
 int RunNewJob (int JobId); // приступить к выполнению нового задания
};

#endif // __TPROC_H__