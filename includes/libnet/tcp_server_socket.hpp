#ifdef __unix__
#include <netinet/in.h>
#include <string>
#endif

#ifndef _LIBNET_TCP_SERVER_SOCKET_HPP_
#define _LIBNET_TCP_SERVER_SOCKET_HPP_ 1

class TCPServerSocket {
    private :
        #ifdef __unix__
        int sockfd; // read only
        struct sockaddr_in addport;
        #endif

        bool is_open = false; // read only

    public :
        TCPServerSocket (char *addr, unsigned short port); // Create socket
        TCPServerSocket (std::string addr, unsigned short port); // Create socket
        void socket_listen (int len); // listening
        int getSocketFd ();
        bool isOpen ();
        void closeSocket ();
        void setKeepAlive (bool keepAlive); // set Keep alive option
        ~TCPServerSocket ();

    private :
        #ifdef __unix__
        void setOpt(int optname, void *optval, unsigned optlen); // set socket option
        void setOpt(int level, int optname, void * optval, unsigned optlen); // set socket option with level
        #endif
};
#endif