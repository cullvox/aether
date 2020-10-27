

# Add sources array
set(aether_sources "")

# Add the proper source files to the array
list(APPEND aether_sources
    "aether.h"
    "a_matrix.c"
    "a_vector.c"
    "a_transform.c"
    "a_mathematical.c"
)


# Create the library
add_library(aether STATIC ${aether_sources})

