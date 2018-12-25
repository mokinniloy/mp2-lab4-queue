#include <iostream>
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

using namespace std;

void simulate(int total_clocks, int queue_size, double q1, double q2) {
    auto job = TJobStream(q1);
    auto proc = TProc(q2);
    TQueue q(queue_size);
    int total_tasks = 0, skipped_tasks = 0, complete_tasks = 0;
    int idle_clocks = 0, busy_clocks = 0;
    int current_task = 0;
    for (int clock = 0; clock < total_clocks; ++clock) {
        int is_complete = proc.tick();
        int task = job.tick();
        if (is_complete) {
            if (proc.get_is_busy()) {
                ++complete_tasks;
            }
            proc.set_is_busy(false);
        }
        if (!proc.get_is_busy()) {
            if (!q.IsEmpty()) {
                current_task = q.Get();
                proc.set_is_busy(true);
            }
        }
        if (task) {
            ++total_tasks;
            if (!q.IsFull())
                q.Put(task);
            else
                ++skipped_tasks;
        }
        (proc.get_is_busy()) ? ++busy_clocks : ++idle_clocks;
    }
    cout << "Total clocks: " << total_clocks << endl;
    cout << "Busy clocks: " << busy_clocks << endl;
    cout << "Idle clocks: " << idle_clocks << " %: " << double(idle_clocks) / total_clocks * 100 << endl;
    cout << "Total tasks: " << total_tasks << endl;
    cout << "Complete tasks: " << complete_tasks << endl;
    cout << "Skipped tasks: " << skipped_tasks << " %: " << double(skipped_tasks) / total_tasks * 100 << endl;
}

int main() {
    simulate(100, 5, .9, .5);
    return 0;
}
