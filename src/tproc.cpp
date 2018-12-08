#include "tproc.h"

TProc::TProc(double q2) {
    probability_upper_bound = q2;
    is_busy = false;
    dist = std::uniform_real_distribution <double>(0, 1);
    generator = std::mt19937(time(0));
}

int TProc::tick() {
    return dist(generator) < probability_upper_bound;
}

bool TProc::get_is_busy() {
    return is_busy;
}

void TProc::set_is_busy(bool statement) {
    is_busy = statement;
}
