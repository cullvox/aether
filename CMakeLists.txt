# Basic CMake setup
cmake_minimum_required(VERSION 3.0.0)
project(aether VERSION 1.0.0 LANGUAGES C)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


# Setup aether options
# TODO : Create options


# Add sources array
set(aether_sources "")

# Add the proper source files to the array
list(APPEND aether_sources
    "source/a_matrix.c"
    "source/a_vector.c"
    "source/a_mathematical.c"
)

# Add the includes
list(APPEND aether_sources
    "include/aether/aether.h"
)


# Create the library
add_library(aether STATIC ${aether_sources})

target_include_directories(aether PUBLIC include)
