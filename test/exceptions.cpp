#include <iostream>
#include <assert.h>

#include "libnet/tcp_server_socket.hpp"
#include "libnet/exceptions.hpp"

void must_throw_exception_on_invalid_ip_address () {
    try {
        TCPServerSocket socket("127.0.0", 8080);
        assert(false);
    } catch (InvalidAddressException ex) {
        assert(true);
    }
}

int main () {
    must_throw_exception_on_invalid_ip_address();
}