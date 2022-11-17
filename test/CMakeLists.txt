project (libnet_test)

include_directories(../includes)
add_executable(libnet_test_exceptions ./exceptions.cpp)
add_executable(libnet_test_basics ./basics.cpp)

target_link_libraries(libnet_test_exceptions LINK_PUBLIC libnet)
target_link_libraries(libnet_test_basics LINK_PUBLIC libnet)