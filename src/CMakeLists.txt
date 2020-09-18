set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

add_library(
    onegin
    sort.cpp
    stringpart.cpp
    utf8.cpp
    utils.cpp
)

target_include_directories(onegin PUBLIC ${INCLUDE_DIR})
