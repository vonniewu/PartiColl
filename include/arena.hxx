#ifndef PARTICOLL_ARENA_HXX
#define PARTICOLL_ARENA_HXX

#include <cstdint>

namespace particoll {

class arena {
    virtual void populate(std::size_t num_shapes) = 0;
};

} // namespace particoll

#endif //PARTICOLL_ARENA_HXX
