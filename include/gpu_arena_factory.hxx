#ifndef PARTICOLL_GPU_ARENA_FACTORY_HXX
#define PARTICOLL_GPU_ARENA_FACTORY_HXX

#include <memory>
#include "arena.hxx"

namespace particoll {

struct gpu_arena_factory {
    std::unique_ptr<arena> create() const;
};

} // namespace particoll

#endif //PARTICOLL_GPU_ARENA_FACTORY_HXX
