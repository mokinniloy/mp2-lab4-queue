#include <iostream>
#include "tjobstream.h"
#include "tproc.h"
#include "tqueue.h"

using namespace std;

int main()
{
    TJobStream task;
    TProc proc;
    int NumTasks = 0, NumComplete = 0, NumRejections = 0, MediumTime = 0, NumEmpty = 0, UnprocessedTasks = 0;
    int Tact = 1000000;
    int QSize = 10;
    TQueue q(QSize);
    for(int i = 0; i < Tact; i++)
    {
        if(task.IsTask())
        {
            ++NumTasks;
            int tmp1 = task.GetTask();
            if(q.IsFull())
                ++NumRejections;
            else
                q.Put(tmp1);
        }
        if(proc.IsEmpty())
        {
            if(q.IsEmpty())
                ++NumEmpty;
            else
            {
                q.Get();
                proc.Busy();
            }
        }
        else
        {
            if(proc.IsComplete())
            {
                ++NumComplete;
                proc.Ready();
                if(q.IsEmpty())
                    ++NumEmpty;
                else
                {
                    q.Get();
                    proc.Busy();
                }
            }
        }
    }

    UnprocessedTasks = q.GetSize();
    if(!proc.IsEmpty())
        ++UnprocessedTasks;
    cout<<"Number of tasks: "<<NumTasks<<"\n";
    cout<<"Number of rejections: "<<double(NumRejections)*100/double(NumTasks)<<"%\n";
    cout<<"Medium time on one task: "<<double(Tact-NumEmpty)/double(NumComplete)<<"\n";
    cout<<"Number of idle tacts: "<<double(NumEmpty)*100/double(Tact)<<"%\n";

    return 0;
}
