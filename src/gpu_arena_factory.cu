#include "gpu_arena_factory.hxx"
#include "gpu_arena.hxx"

const std::unique_ptr<arena> particoll::gpu_arena_factory::create() const -> std::unique<arena> {
    return new gpu::gpu_arena;
}