#include "tjobstream.h"

TJobStream::TJobStream(double q1) {
	probability_upper_bound = q1;
	task_id = 0;
	dist = std::uniform_real_distribution <double>(0, 1);
	generator = std::mt19937(time(0) + 1);
}

int TJobStream::tick() {
	return (dist(generator) < probability_upper_bound) ? task_id++ : 0;
}