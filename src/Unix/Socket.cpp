#include <sys/socket.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "libnet/config.hpp"
#include "libnet/Socket.hpp"

Socket::Socket () {
    this->socket = INVALID_SOCKET;
}

Socket::Socket(SocketType type) {
    int t = type == SocketType::tcp ? SOCK_STREAM : SOCK_DGRAM;

    this->socket = ::socket(PF_INET, t, 0); // Create socket from syscall

    address.sin_family = AF_INET; //Set address family to IPv4
}

Socket::Socket(socket_t socket) {
    // Get file descriptor flags to check if fd is valid
    // Just a cheap trick to check socket is valid
    
    int flags = fcntl(socket, F_GETFD);

    // if fd is invalid fcntl will return -1

    if (flags < 0) {
        // TODO Must Throw error if this failes
    }   

    this->socket = socket;
}
        
void Socket::bind (const char *ip_address, uint16_t port) {
    int bind_ret;

    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip_address);
                
    bind_ret = ::bind(this->socket, (struct sockaddr *)&address, sizeof(address));
         
    if (bind_ret < 0) {
        // TODO This should throw an error with propriote message
    }
}

void Socket::bind (std::string ip_address, uint16_t port) {
    this->bind(ip_address.c_str(), port);
}

void Socket::listen () {
    int listen_ret = ::listen(this->socket, DEFAULT_BACKLOG_SIZE);

    if (listen_ret < 0) {
        // TODO This should throw an error with propriote message
    }
}


void Socket::setBlocking (bool blocking) {
    if (blocking) {
        fcntl(this->socket, F_SETFL, fcntl(this->socket, F_GETFL) & ~O_NONBLOCK); 
    } else {
        fcntl(this->socket, F_SETFL, fcntl(this->socket, F_GETFL) | O_NONBLOCK);         
    }
}
        

int Socket::getFd () {
    return this->socket;
}

void Socket::close () {
    if (::close(this->socket) < 0) {
        // TODO This should throw an error with propriote message 
    }
}

Socket Socket::accept() {
    struct sockaddr_in client_address;
    unsigned int len;

    int client_fd = ::accept(this->socket, (struct sockaddr *)&client_address, &len);

    Socket client_socket(client_fd);
    client_socket.address = client_address;

    return client_socket;
}
        
// Flags are not supported
void Socket::send (char *buffer, int len) {
    int send_ret = ::send(this->socket, buffer, len, 0);

    if (send_ret < 0) {
        // TODO this means socket is invalid and it MUST throw an error
    }
}

int Socket::recv (char *buffer, int len) {
    int recv_len = ::recv(this->socket, buffer, len, 0);

    if (recv_len == 0) {
        // TODO This means that the socket is invalid or closed and MUST throw error 
    } 

    return recv_len;
}   


void Socket::connect(const char *ip_address, uint16_t port) {
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip_address);

    int connect_ret = ::connect(socket, (struct sockaddr *)&address, sizeof(address));

    if (connect_ret < 0) { // This means connection failed for some reason
        // TODO should throw erro with the propriote message
    }
}

void Socket::connect(std::string ip_address, uint16_t port) {
    this->connect(ip_address.c_str(), port);
}

bool Socket::getBlocking() {
    int flags = fcntl(this->socket, F_GETFL);
    
    bool non_block_flag_set = flags & O_NONBLOCK;

    return !non_block_flag_set;
}

// FIXME this just check if socket fd greater than -1. MUST find more efficent way to do this
bool Socket::isValid() {
    return this->socket > INVALID_SOCKET;
}
