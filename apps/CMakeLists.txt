# set(INCLUDE_DIR "${OneginSort_SOURCE_DIR}/include")
# set(HEADER_LIST "${INCLUDE_DIR}/onegin/hello.h"/)

# library for printing "hello, world"
add_executable(
    main
    main.cpp
    # ${HEADER_LIST}
)

# target_include_directories(main PUBLIC ${INCLUDE_DIR})
target_include_directories(main PUBLIC ${OneginSort_SOURCE_DIR}/include)

target_link_libraries(main hello)
