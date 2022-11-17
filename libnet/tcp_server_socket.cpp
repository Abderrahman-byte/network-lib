#include <netinet/in.h>
#include <string>
#include <bits/stdc++.h> 
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

#include "libnet/tcp_server_socket.hpp"
#include "libnet/exceptions.hpp"

TCPServerSocket::TCPServerSocket (char *addr, unsigned short port) {
    int opt = 1;

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

    this->addport.sin_family = AF_INET;
    this->addport.sin_port = htons(port);

    // using inet_pton instead inet_addr because it returns less than 0 if address if invalid
    if (inet_pton(AF_INET, addr, &this->addport.sin_addr) <= 0) {
        throw InvalidAddressException();
    }

    setsockopt(this->sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    bind(this->sockfd, (sockaddr *)(&this->addport), sizeof(this->addport));
    
    this->is_open = true;
}

TCPServerSocket::TCPServerSocket (std::string addr, unsigned short port) {
    char addr_char[addr.length()];

    strcpy(addr_char, addr.c_str());

    TCPServerSocket(addr_char, port);
}

void TCPServerSocket::socket_listen (int len) {
    listen(this->sockfd, len);
}

void TCPServerSocket::setOpt(int optname, void *optval, unsigned optlen) {
    this->setOpt(SOL_SOCKET, optname, optval, optlen);
}

void TCPServerSocket::setOpt(int level, int optname, void * optval, unsigned optlen) {
    int a = setsockopt(this->sockfd, level, optname, optval, optlen);
}

bool TCPServerSocket::isOpen () {
    return this->is_open;
}

void TCPServerSocket::closeSocket () {
    if (!this->is_open) throw InvalidSocketFd();
    
    close(this->sockfd);
    this->is_open = false;
}

void TCPServerSocket::setKeepAlive (bool KeepAlive) {
    int val = KeepAlive ? 1 : 0;
    this->setOpt(SO_KEEPALIVE, &val, sizeof val);
}


int TCPServerSocket::getSocketFd () {
    return this->sockfd;
}

TCPServerSocket::~TCPServerSocket () {
    std::cout << "Must decontruct" << std::endl;
}