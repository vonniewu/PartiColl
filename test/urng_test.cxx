#include <gtest/gtest.h>
#include <array>
#include <iostream>
#include "urng.hxx"

TEST(urng_test, same_numbers_generated_from_seed) {
    // Fill an array full of integers from one instance of an urng object.
    // Fill another array full of integers from ANOTHER instance of an urgn object.
    // Compare to see if both instances filled the array with the correct values.

    constexpr int SEED = 1121;
    constexpr int START_RANGE = 0;
    constexpr int END_RANGE = 1000;
    constexpr int OBJECT_COUNTS = 1000;

    particoll::urng urng1{SEED, START_RANGE, END_RANGE};
    particoll::urng urng2{SEED, START_RANGE, END_RANGE};

    std::array<int, OBJECT_COUNTS> urng1_array;
    std::array<int, OBJECT_COUNTS> urng2_array;

    std::generate(std::begin(urng1_array), std::end(urng1_array), [&]() {
       return urng1.get_next();
    });

    std::generate(std::begin(urng2_array), std::end(urng2_array), [&]() {
        return urng2.get_next();
    });

    EXPECT_TRUE(std::equal(std::begin(urng1_array), std::end(urng1_array), std::begin(urng2_array)));
}

TEST(urng_test, verify_range_of_values_from_seed) {
    constexpr int SEED = 1121;
    constexpr int START_RANGE = 0;
    constexpr int END_RANGE = 1000;
    constexpr int OBJECT_COUNTS = 1000;

    particoll::urng urng1{SEED, START_RANGE, END_RANGE};

    std::array<int, OBJECT_COUNTS> urng1_array;

    std::generate(std::begin(urng1_array), std::end(urng1_array), [&]() {
        return urng1.get_next();
    });

//    std::all_of();
}
