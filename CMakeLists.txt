cmake_minimum_required(VERSION 3.10)

project(OneginSort VERSION 0.1
                   DESCRIPTION "Onegin sort program"
                   LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wfloat-equal")
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

add_subdirectory(src)
add_subdirectory(apps)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    include(GoogleTest)
    enable_testing()
    add_subdirectory(test)
endif()

# todo: check if available, run only in RELEASE
find_package(Doxygen)
add_subdirectory(docs)
