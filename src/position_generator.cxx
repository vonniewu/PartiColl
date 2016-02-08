#include "position_generator.hxx"

auto particoll::position_generator::get_next() -> particle::position_t {
    return {x_rng.get_next(), y_rng.get_next()};
}
