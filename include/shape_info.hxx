#ifndef PARTICOLL_SHAPE_INFO_HXX
#define PARTICOLL_SHAPE_INFO_HXX

#include "shape.hxx"

namespace particoll {

struct rectangle_info_t {
    using length_t = int;
    const length_t width, height;
};

struct circle_info_t {
    using radius_t = int;
    const radius_t radius;
};

union shape_info_t {
    rectangle_info_t rect;
    circle_info_t circle;
};

class shape_info {

public:
    shape_info(const rectangle_info_t &rect_info);
    shape_info(const circle_info_t &circle_info);

    const shape_t &get_shape() const;
    const shape_info_t &get_shape_info() const;

private:
    const shape_t shape;
    const shape_info_t info;
};

} // namespace particoll

#endif //PARTICOLL_SHAPE_INFO_HXX
