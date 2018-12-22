#include <iostream>
#include "tproc.h"
#include "tjobstream.h"
#include "tqueue.h"
#include <limits.h>
using namespace std;

int main()
{
    int tacts,stream_len=INT_MAX,qsize,idle_tacts=0,queue_overflow=0,complete=0,put_t=0,num_t=0;
    double proc_bar,stream_bar;
    cin >> tacts >> qsize >> proc_bar >> stream_bar;
    TQueue q(qsize);
    TJobStream job(stream_len,stream_bar);
    TProc proc(proc_bar);
    for (int i=0;i<tacts;++i)
    {
        int g=job.next();
        if (g!=-1)
        {
            if (q.IsFull())
                ++queue_overflow;
            else
            {
                q.Put(g);
                ++put_t;
            }
            ++num_t;
        }
        if (proc.has_task())
            if (proc.task_ready())
                ++complete;
        if (!proc.has_task())
            if (q.IsEmpty())
                ++idle_tacts;
            else
            {
                q.Get();
                proc.push();
            }
    }
    cout << "tasks get: " << num_t << '\n';
    cout << "percent of rejection in queue: " << 100.0*queue_overflow/num_t << "%\n";
    cout << "average value of tacts for task: " << (double)(tacts-idle_tacts)/complete << '\n';
    cout << "percent of idle tacts: " << 100.0*idle_tacts/tacts << "%\n";
}
