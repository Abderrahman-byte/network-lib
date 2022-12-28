#include <string>

#ifndef _LIBNET_TCP_CONNECTION_HPP_
#define _LIBNET_TCP_CONNECTION_HPP_ 1

class TCPConnection {
    private :
        bool is_open;

    public :
        TCPConnection(std::string address, uint16_t port);
        TCPConnection();

        void setAddress(std::string address);
        void setPort(uint16_t port);

        std::string getAddress();
        uint16_t getPort();

        void close();
        bool isOpen();

        bool send (char *buffer, unsigned len);
        bool receive (char *buffer, unsigned len);
};

#endif