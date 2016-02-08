#ifndef PARTICOLL_GPU_ARENA_HXX
#define PARTICOLL_GPU_ARENA_HXX

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

#include "arena.hxx"
#include "constants.hxx"
#include "shape_generator.hxx"
#include "position_generator.hxx"
#include "velocity_generator.hxx"

namespace particoll {
namespace gpu {

class gpu_arena : public arena {
public:
    virtual void populate(std::size_t num_shapes) {
        y_pos.reserve(num_shapes);
        x_pos.reserve(num_shapes);

        x_vels.reserve(num_shapes);
        y_vels.reserve(num_shapes);

        shape_widths.reserve(num_shapes);
        shape_heights.reserve(num_shapes);

        // Generators
        shape_generator shape_gen;
        velocity_generator velocity_gen;
        position_generator position_gen;

        for (auto i = 0u; i < num_shapes; ++i) {
            auto shape = shape_gen.get_next();
            auto pos = position_gen.get_next();
            auto vel = velocity_gen.get_next();

            shape_widths.push_back(shape.get_shape_info().rect.width);
            shape_heights.push_back(shape.get_shape_info().rect.height);

            x_vels.push_back(vel.first);
            y_vels.push_back(vel.second);

            x_pos.push_back(pos.first);
            y_pos.push_back(pos.second);
        }
    }

private:
    thrust::host_vector<int> x_pos;
    thrust::host_vector<int> y_pos;

    thrust::host_vector<int> x_vels;
    thrust::host_vector<int> y_vels;

    thrust::host_vector<int> shape_widths;
    thrust::host_vector<int> shape_heights;
};

} // namespace gpu
} // namespace particoll

#endif //PARTICOLL_GPU_ARENA_HXX
