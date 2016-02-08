#include <utility>

#include "shape.hxx"
#include "shape_info.hxx"

#ifndef PARTICOLL_PARTICLE_HXX
#define PARTICOLL_PARTICLE_HXX

namespace particoll {

class particle {

public:
    using id_t = int;
    using position_t = std::pair<int, int>;
    using velocity_t = std::pair<int, int>;

    explicit particle(id_t id, const position_t &position, const velocity_t &velocity, const shape_info &shape);

    id_t get_id() const;
    const position_t &get_current_position() const;
    const velocity_t &get_velocity() const;
    const shape_info &get_shape() const;

    void set_position(const position_t &new_position);
    void set_velocity(const velocity_t &new_velocity);

private:
    id_t id;
    position_t current_position;
    velocity_t velocity;
    const shape_info shape;
};

} // namespace particoll

#endif //PARTICOLL_PARTICLE_HXX
