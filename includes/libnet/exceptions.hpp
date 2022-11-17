#include <string>
#include <exception>

#ifndef _LIBNET_EXCEPTIONS_HPP_
#define _LIBNET_EXCEPTIONS_HPP_ 1

#define INVALID_ADDRESS_DEFAULT_MSG "the given address is invalid"
#define INVALID_SOCKET_FD_DEFAULT_MSG "the socket file descriptor is invalid"
#define SET_SOCKET_OPTION_DEFAULT_MSG "couldn't set socket option"

class InvalidAddressException : public std::exception {
    public :
        const char* what();
};

class InvalidSocketFd : public std::exception {
    public :
        const char* what();
};

class SetSocketOptionException : public std::exception {
    public :
        const char* what();
};

#endif