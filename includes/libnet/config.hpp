#ifndef _NETLIB_CONFIG_HPP_

#define DEFAULT_BACKLOG_SIZE 1280

#ifdef __unix__ // Unix-like specific macros and types
    typedef int socket_t; // Just an alias for socket() return type

    #define INVALID_SOCKET -1;

#elif defined(_WIN32) || defined(WIN32) // Windows Macros

    typedef unsigned int socket_t;

#endif

#endif // !_NETLIB_CONFIG_HPP_
