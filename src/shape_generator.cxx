#include "shape_generator.hxx"

auto particoll::shape_generator::get_next() -> shape_info {
    // TODO: For now only creating rectangle shapes.
    return particoll::rectangle_info_t{width_rng.get_next(), height_rng.get_next()};
}