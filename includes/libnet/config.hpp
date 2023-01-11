#ifndef _NETLIB_CONFIG_HPP_

#define DEFAULT_BACKLOG_SIZE 1280

/** \cond */
#ifdef __unix__ // Unix-like specific macros and types
    #define INVALID_SOCKET -1

    /// Just an alias for socket() return type
    typedef int socket_t;

#elif defined(_WIN32) || defined(WIN32) // Windows Macros

    typedef unsigned int socket_t;

#endif
/** \endcond */

#endif // !_NETLIB_CONFIG_HPP_
