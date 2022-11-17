cmake_minimum_required(VERSION 3.11)

project (networking_lib)

add_subdirectory(./libnet)

if (BUILD_TESTS)
    add_subdirectory(./test)
endif()