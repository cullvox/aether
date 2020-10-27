# Basic CMake setup
cmake_minimum_required(VERSION 3.0.0)
project(aether VERSION 1.0.0 LANGUAGES C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


# Setup aether options
# TODO : Create options

add_subdirectory(source)