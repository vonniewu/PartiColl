#include <shape.hxx>
#include "shape_info.hxx"

particoll::shape_info::shape_info(const circle_info_t &circle_info)
    : shape{shape_t::CIRCLE}, info{.circle = circle_info} {}

particoll::shape_info::shape_info(const rectangle_info_t &rect_info)
    : shape{shape_t::RECTANGLE}, info{.rect = rect_info} {}

auto particoll::shape_info::get_shape() const -> const shape_t& { return shape; }

auto particoll::shape_info::get_shape_info() const -> const shape_info_t& { return info; }
