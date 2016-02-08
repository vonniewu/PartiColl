#ifndef PARTICOLL_VELOCITY_GENERATOR_HXX
#define PARTICOLL_VELOCITY_GENERATOR_HXX

#include "particle.hxx"
#include "urng.hxx"
#include "seeds.hxx"
#include "constants.hxx"

namespace particoll {

class velocity_generator {
public:
    particle::velocity_t get_next();

private:
    urng x_rng{seeds::X_VELOCITY_SEED, constants::MIN_VELOCITY, constants::MAX_VELOCITY};
    urng y_rng{seeds::Y_VELOCITY_SEED, constants::MIN_VELOCITY, constants::MAX_VELOCITY};
};

} // namespace particoll

#endif //PARTICOLL_VELOCITY_GENERATOR_HXX
