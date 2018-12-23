#ifndef __TJOBSTREAM_H__
#define __TJOBSTREAM_H__

class TJobStream {
 private:
 double JobIntеns; // интенсивность потока задач
 public:
 TJobStream (double Intеns);
 int GetNewJob(void); // генерация нового задания
};

#endif // __TJOBSTREAM_H__