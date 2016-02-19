#include <utility>

#include "shape_info.hxx"
#include "particle.hxx"

particoll::particle::particle(id_t id, const position_t &position, const velocity_t &velocity, const shape_info &shape)
    : id{id}, current_position{position}, velocity{velocity}, shape{shape} {}

auto particoll::particle::get_id() const -> id_t {
    return id;
}

auto particoll::particle::get_current_position() const -> const position_t& {
    return current_position;
}

auto particoll::particle::get_velocity() const -> const velocity_t& {
    return velocity;
}

auto particoll::particle::get_shape() const -> const shape_info& {
    return shape;
}

void particoll::particle::set_position(const position_t &new_position) {
    this->current_position = new_position;
}

void particoll::particle::set_velocity(const velocity_t &new_velocity) {
    this->velocity = new_velocity;
}



