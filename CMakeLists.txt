cmake_minimum_required(VERSION 2.8)
project(PartiColl)

set(CUDA_TOOLKIT_ROOT_DIR /opt/cuda)

find_package(CUDA QUIET REQUIRED)

set(CMAKE_CXX_FLAGS "-O0 -std=c++11")
add_definitions(-D_MWAITXINTRIN_H_INCLUDED)

set(
    CUDA_NVCC_FLAGS_GENERAL
    ${CUDA_NVCC_FLAGS};
)

set(
    CUDA_NVCC_FLAGS_DEBUG
    ${CUDA_NVCC_FLAGS};
    ${CUDA_NVCC_FLAGS_GENERAL};
    -g
    -O0
    -arch=sm_20
    -DVERBOSE
)

set(
    CUDA_NVCC_FLAGS_RELEASE
    ${CUDA_NVCC_FLAGS};
    ${CUDA_NVCC_FLAGS_GENERAL};
    -O3
)

include_directories("./include")

set(PARTICOLL_LIB_SRC_FILES src/gpu_arena.cu)
cuda_add_library(${PROJECT_NAME}Lib ${PARTICOLL_LIB_SRC_FILES})

set(SRC_FILES
    src/urng.cxx src/particle.cxx src/shape_info.cxx src/shape_generator.cxx src/velocity_generator.cxx src/position_generator.cxx)

cuda_add_executable(
    ${PROJECT_NAME}
    ${SRC_FILES}
    main.cxx
)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Lib)

# Tell CMake to build the gtest library.
add_subdirectory("lib/googletest/googletest")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#Add all of the test source files.
set(TEST_SRC_FILES "test/main_test.cxx" test/urng_test.cxx)

# Tell CMake to build an executable for the tests.
cuda_add_executable(${PROJECT_NAME}Tests ${TEST_SRC_FILES} ${SRC_FILES})

# Link test executable against gtest & gtest_main.
# Linking to gtest_main allows us to avoid writing a main_test.cpp for the tests.
# target_link_libraries(${PROJECT_NAME}Tests gtest gtest_main ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}Tests ${PROJECT_NAME}Lib gtest gtest_main)
