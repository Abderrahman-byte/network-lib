#include <gtest/gtest.h>
#include <iostream>

#include "libnet/Socket.hpp"
#include "libnet/config.hpp"

TEST(Socket, SocketCreate) {
    Socket socket(SocketType::tcp);

    EXPECT_NE(INVALID_SOCKET, socket.getFd()); 

    socket.close();
}

TEST(Socket, SocketNONBLOCK) {
    Socket socket(SocketType::tcp);

    ASSERT_TRUE(socket.getBlocking());
    
    socket.setBlocking(false);

    ASSERT_FALSE(socket.getBlocking());

    socket.setBlocking(true);

    ASSERT_TRUE(socket.getBlocking()); 

    socket.close();
}
