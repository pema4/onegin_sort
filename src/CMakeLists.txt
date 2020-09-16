set(INCLUDE_DIR "${OneginSort_SOURCE_DIR}/include")
# set(HEADER_LIST "${INCLUDE_DIR}/onegin/hello.h"/)

# library for printing "hello, world"
add_library(
    hello 
    hello.cpp
    # ${HEADER_LIST}
)

# target_include_directories(hello PUBLIC ${INCLUDE_DIR})
target_include_directories(hello PUBLIC ${OneginSort_SOURCE_DIR}/include)
