#ifndef PARTICOLL_SHAPE_GENERATOR_HXX
#define PARTICOLL_SHAPE_GENERATOR_HXX

#include "urng.hxx"
#include "shape_info.hxx"
#include "seeds.hxx"
#include "constants.hxx"

namespace particoll {

class shape_generator {
public:
    shape_info get_next();

private:
    urng width_rng{seeds::SHAPE_WIDTH_SEED, constants::MIN_SHAPE_LENGTH, constants::MAX_SHAPE_LENGTH};
    urng height_rng{seeds::SHAPE_HEIGHT_SEED, constants::MIN_SHAPE_LENGTH, constants::MAX_SHAPE_LENGTH};
};

} // namespace particoll

#endif //PARTICOLL_SHAPE_GENERATOR_HXX
