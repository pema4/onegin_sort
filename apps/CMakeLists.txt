# library for printing "hello, world"
add_executable(
    main
    main.cpp
    # ${HEADER_LIST}
)

target_include_directories(main PUBLIC ${PROJET_SOURCE_DIR}/include)

target_link_libraries(main onegin)
