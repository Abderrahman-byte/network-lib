#ifndef _LIBNET_SOCKET_TYPE_HPP
#define _LIBNET_SOCKET_TYPE_HPP 1

/**
 * @brief Reference to Transport-Layer protocol
 * @date 2023-01-10
 **/
enum class SocketType { 
    /// TCP connection-based socket type
    tcp,
    /// UDP connection-less socket type 
    udp
};

#endif // !_LIBNET_SOCKET_TYPE_HPP
