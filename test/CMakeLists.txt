cmake_minimum_required(VERSION 3.10)
project(grid)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

enable_testing()

find_package(Catch2 REQUIRED)
include(Catch)

if(NOT TARGET grid::grid)
    find_package(grid CONFIG REQUIRED)
endif()

add_library(test-main OBJECT test-main.cpp)
target_link_libraries(test-main PUBLIC Catch2::Catch2)

add_executable(test-grid test-grid.cpp)
target_link_libraries(test-grid PRIVATE test-main grid)
catch_discover_tests(test-grid)
