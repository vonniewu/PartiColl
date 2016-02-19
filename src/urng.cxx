#include "urng.hxx"

particoll::urng::urng(int seed, int startRange, int endRange)
    : engine{seed}, distribution{startRange, endRange} {}

int particoll::urng::get_next() {
    return distribution(engine);
}