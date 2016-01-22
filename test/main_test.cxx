#include <gtest/gtest.h>
#include "fill.h"
#include <algorithm>

constexpr int blocksize = 100;
#include <iostream>

TEST(MainCudaTests, CudaWorks) {
    std::array<int, blocksize> numbers;
    
    auto fill = runFill();
    
    std::cout << fill << std::endl;
}
