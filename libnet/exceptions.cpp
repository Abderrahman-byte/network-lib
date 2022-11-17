#include "libnet/exceptions.hpp"

const char* InvalidAddressException::what () {
    return INVALID_ADDRESS_DEFAULT_MSG;
}

const char* InvalidSocketFd::what() {
    return INVALID_SOCKET_FD_DEFAULT_MSG;
}

const char* SetSocketOptionException::what () {
    return SET_SOCKET_OPTION_DEFAULT_MSG;
}