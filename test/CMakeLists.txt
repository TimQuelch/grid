cmake_minimum_required(VERSION 3.10)
project(grid)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

enable_testing()

find_package(Catch2 REQUIRED)

if(NOT TARGET grid::grid)
    find_package(grid CONFIG REQUIRED)
endif()

add_library(test-main OBJECT test-main.cpp)
target_link_libraries(test-main Catch2::Catch2)
