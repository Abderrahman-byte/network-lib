#include <string>

#ifdef __unix__

#include <netinet/in.h>

#endif // Unix-like platform specific includes

#if defined(_WIN32) || defined(WIN32) 

#endif // Windows includes

#ifndef _LIBNET_SOCKET_
#define _LIBNET_SOCKET_ 1

#define DEFAULT_BACKLOG_SIZE 1280

#ifdef __unix__         

typedef int socket_t; // Just an alias for socket() return type
#define INVALID_SOCKET -1;

#elif defined(_WIN32) || defined(WIN32)

typedef unsigned int socket_t;

#endif

// Reference to Transport-Layer protocol
enum class SocketType { 
    tcp,
    udp
};

// This class is a wrapper for native socket 
// its purpose to be used as an platform agnostic API

class Socket {
    private :
        socket_t socket = INVALID_SOCKET;
        struct sockaddr_in address;

    public :
        // this constructor is used to create new socket
        Socket(SocketType type); 

        // this constructor wrappes an already existing socket
        Socket(socket_t);
        
        int getFd ();

        // Bind a socket to an ip address and port
        void bind (const char *ip_address, uint16_t port);
        void bind (std::string ip_address, uint16_t port);
    
        void listen (); // used in Server side

        // Set/unset O_NONBLOCK flag
        void setBlocking (bool blocking);
        bool getBlocking (); 
        
        // Flags are not supported
        void send (char *buffer, int len);
        int recv (char *buffer, int len);
        
        void connect(char const *ip, uint16_t); // Used in the client side to connect to a server
        void connect(std::string ip, uint16_t); 

        Socket accept(); // used in connection-based server side

        void close ();
};


#endif // !_LIBNET_SOCKET_
