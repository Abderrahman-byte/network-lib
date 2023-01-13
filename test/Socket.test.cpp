#include <gtest/gtest.h>
#include <iostream>

#include "libnet/Socket.hpp"
#include "libnet/config.hpp"

class SocketTest : public ::testing::Test {
    protected:
        Socket socket;

        void SetUp() override {
            this->socket = Socket(SocketType::tcp);
        }
        
        void TearDown() override {
            this->socket.close();
        }
};

TEST_F(SocketTest, Basics) {
    ASSERT_NE(INVALID_SOCKET, socket.getFd()); // Check if socket is invalid 

    ASSERT_TRUE(socket.isValid()); // Check if socket is invalid 

    ASSERT_TRUE(socket.getBlocking()) << "Socket should be blocking by default"; 
    
    socket.setBlocking(false);

    ASSERT_FALSE(socket.getBlocking()) << "Socket should be non-block after setBlocking(false)";

    socket.setBlocking(true);

    ASSERT_TRUE(socket.getBlocking()) << "Socket should be non-block after setBlocking(false)";
}

TEST(Socket, InvalidSocket) {
    Socket socket;

    EXPECT_FALSE(socket.isValid());
}
