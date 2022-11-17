#include <iostream>
#include <assert.h>

#include "libnet/tcp_server_socket.hpp"

int main () {
    TCPServerSocket server("127.0.0.1", 8080);

    server.setKeepAlive(true);
    server.socket_listen(10);
    server.setKeepAlive(false);

    while (true) {}
}