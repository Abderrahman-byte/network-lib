project(libnet)

set(LIBNET_SRCS
    exceptions.cpp
    tcp_server_socket.cpp
)

include_directories(../includes)

add_library(libnet STATIC ${LIBNET_SRCS})