cmake_minimum_required(VERSION 3.11)

project (networking_lib VERSION 0.9.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC )

if (WIN32)
    list(APPEND SRC ${SRCROOT}/Win32/Socket.cpp)
else () 
    list(APPEND SRC ${SRCROOT}/Unix/Socket.cpp)
endif()


include_directories(./includes/)

add_library(net ${SRC})

# if (BUILD_TESTS)
#     add_subdirectory(./test)
# endif()
