#include "velocity_generator.hxx"

auto particoll::velocity_generator::get_next() -> particle::velocity_t {
    return {x_rng.get_next(), y_rng.get_next()};
}
