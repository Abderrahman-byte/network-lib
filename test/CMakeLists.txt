project (libnet_test)

SET(LIBNET_TEST_SRC
    Socket.test.cpp
)

include(FetchContent)

if (WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/GoogleTest
    GIT_TAG v1.12.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

add_executable(
    libnet_test
    ${LIBNET_TEST_SRC}
)

target_link_libraries(
    libnet_test
    GTest::gtest_main
    libnet
)

gtest_discover_tests(libnet_test)
