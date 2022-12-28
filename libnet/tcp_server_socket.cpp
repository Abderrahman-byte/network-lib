#ifdef __unix__
// Linux Specifique includes

#include <netinet/in.h>
#include <string>
#include <bits/stdc++.h> 
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32) 
// WINDOWS specifique includes

#endif

#include "libnet/tcp_server_socket.hpp"
#include "libnet/exceptions.hpp"

#ifdef __unix__
// Linux Specifique implementations

#elif defined(_WIN32) || defined(WIN32) 
// WINDOWS specifique implementations

#endif