enable_testing()

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_executable(testHello testHello.cpp)

target_include_directories(
    testHello
    PUBLIC
    ${PROJECT_SOURCE_DIR}/extern/googletest/googletest/include
)

target_link_libraries(testHello gtest gtest_main)
gtest_discover_tests(testHello)
