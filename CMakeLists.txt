cmake_minimum_required(VERSION 3.11)
project (networking_lib VERSION 0.9.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC )

if (WIN32)
    list(APPEND SRC ${SRCROOT}/Win32/Socket.cpp)
else () 
    list(APPEND SRC ${SRCROOT}/Unix/Socket.cpp)
endif()


if(DOC_ONLY)
    add_subdirectory(docs)
else()
    add_library(libnet ${SRC})

    target_include_directories(libnet PUBLIC ./includes/)
    
    if (BUILD_TESTS)
        enable_testing()
        add_subdirectory(./test)
    endif()
endif()

