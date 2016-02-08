#ifndef PARTICOLL_POSITION_GENERATOR_HXX
#define PARTICOLL_POSITION_GENERATOR_HXX

#include "particle.hxx"
#include "seeds.hxx"
#include "urng.hxx"
#include "constants.hxx"

namespace particoll {

class position_generator {
public:
    particle::position_t get_next();

private:
    urng x_rng{seeds::X_POSITION_SEED, 0, constants::ARENA_WIDTH};
    urng y_rng{seeds::Y_POSITION_SEED, 0, constants::ARENA_HEIGHT};
};

} // namespace particoll

#endif //PARTICOLL_POSITION_GENERATOR_HXX
