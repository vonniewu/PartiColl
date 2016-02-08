#ifndef URNG_HXX_
#define URNG_HXX_

#include <random>

namespace particoll {

class urng {

std::default_random_engine engine;
std::uniform_int_distribution<int> distribution;

public:
    explicit urng(int seed, int start_range, int end_irange);
    int get_next();
};

} // namespace particoll

#endif // URNG_HXX_