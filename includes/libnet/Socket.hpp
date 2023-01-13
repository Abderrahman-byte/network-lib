#include <string>



#ifdef __unix__

    #include <netinet/in.h>

#endif // Unix-like platform specific includes


#if defined(_WIN32) || defined(WIN32) 

#endif // Windows includes



#include "libnet/config.hpp"



#ifndef _LIBNET_SOCKET_
#define _LIBNET_SOCKET_ 1


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


/**
 * @brief A class wrapper for native socket 
 * @details the main purpose is to provide a platform agnostic API for socket programming
 * @date 2023-01-10
**/ 
class Socket {
    private :
        socket_t socket = INVALID_SOCKET;
        struct sockaddr_in address;

    public :
        /** 
         * @brief this constructor is used to create new socket 
         * @param type specifies if socket is tcp or udp
         **/
        Socket(SocketType type); 

        /**
         * @brief this constructor wrappes an already existing socket 
         * @param socket the socket file descriptor
         *
         **/
        Socket(socket_t socket);
        
        /**
         * @brief Returns the file descriptor for the socket
         * @return the file descriptor of the socket
         **/        
        socket_t getFd ();

        /** 
         * @brief Bind a socket to an ip address and port
         * @param ip_address the ip address
         * @param port the port
         **/
        void bind (const char *ip_address, uint16_t port);

        /** 
         * @brief Bind a socket to an ip address and port 
         * @param ip_address the ip address
         * @param port the port
         **/
        void bind (std::string ip_address, uint16_t port);

        /**
         * @brief Start listenning for incomming request
         * @details This method is used in the server side.
         **/
        void listen ();

        /**
         * @brief Set/unset O_NONBLOCK flag 
         * @param blocking specifies to set or unset the flag
         **/
        void setBlocking (bool blocking);

        /**
         * @brief Checks if O_NONBLOCK is set
         * @return true if the socket is set to non-blocking
         **/
        bool getBlocking (); 
        
        /**
         * @brief Sends data to the other end of the socket
         * @param[in] buffer the data to be sent
         * @param len the length of the data
         **/
        void send (char *buffer, int len);

        /**
         * @brief Receives data from the other end of the socket
         * @param[out] buffer a buffer array where to put the received data
         * @param len The buffer length
         * @return the length of the received data
         **/
        int recv (char *buffer, int len);
        
        /**
         * @brief Connect to a server socket
         * @param ip the ip address of the server
         * @param port the port of the server
         * @details This method is only used in the client-side in tcp socket
         **/
        void connect(char const *ip, uint16_t port); 

        /**
         * @brief Connect to a server socket
         * @param ip the ip address of the server
         * @param port the port of the server
         * @details This method is only used in the client-side in tcp socket
         **/
        void connect(std::string ip, uint16_t port); 
        
        /**
         * @brief Accept incomming tcp connection
         * @details This method is only used in tcp server-side
         * @return A refrence to the client socket 
         **/
        Socket accept(); 

        /**
         * @brief Close the socket
         **/
        void close ();
};

#endif // !_LIBNET_SOCKET_