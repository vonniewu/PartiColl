cmake_minimum_required(VERSION 3.4)
project(PartiColl)

set(CUDA_TOOLKIT_ROOT_DIR /opt/cuda)

find_package(CUDA QUIET REQUIRED)

set(CMAKE_CXX_FLAGS "-O0 -std=c++11")

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

set(PARTICOLL_LIB_SRC_FILES "src/fill.cu")
cuda_add_library(${PROJECT_NAME}Lib ${PARTICOLL_LIB_SRC_FILES})

set(PARTICOLL_SRC_FILES "main.cu")

cuda_add_executable(
    ${PROJECT_NAME}
    ${PARTICOLL_SRC_FILES}
)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Lib)


if (GTEST STREQUAL "ON")

	# Tell CMake to build the gtest library.
	add_subdirectory("lib/googletest/googletest")
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

	#Add all of the test source files.
	set(TEST_SRC_FILES "test/main_test.cxx")

	# Tell CMake to build an executable for the tests.
	add_executable(${PROJECT_NAME}Tests ${TEST_SRC_FILES})

	# Link test executable against gtest & gtest_main.
	# Linking to gtest_main allows us to avoid writing a main_test.cpp for the tests.
	# target_link_libraries(${PROJECT_NAME}Tests gtest gtest_main ${PROJECT_NAME})
	target_link_libraries(${PROJECT_NAME}Tests ${PROJECT_NAME}Lib gtest gtest_main)

endif()
