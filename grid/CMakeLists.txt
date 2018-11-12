cmake_minimum_required(VERSION 3.10)
project(grid VERSION 0.1.0)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

find_package(fmt REQUIRED)

# Build
add_library(grid INTERFACE)
add_library(grid::grid ALIAS grid)
target_include_directories(
    grid
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include/>)

# Install
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/grid)

install(
    TARGETS grid
    EXPORT grid-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
    EXPORT grid-targets
    FILE gridTargets.cmake
    NAMESPACE grid::
    DESTINATION ${INSTALL_CONFIGDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/gridConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/gridConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/gridConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR})

install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/gridConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/gridConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR})

export(
    EXPORT grid-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/gridTargets.cmake
    NAMESPACE grid::)

export(PACKAGE grid)
