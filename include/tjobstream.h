#ifndef __TJOBSTREAM_H__
#define __TJOBSTREAM_H__
#include <random>
#include <ctime>

class TJobStream {
private:
    std::mt19937 generator;
    std::uniform_real_distribution <double> dist;
    double probability_upper_bound;
    int task_id;
public:
    TJobStream(double q1);
    int tick();
};

#endif // __TJOBSTREAM_H__
