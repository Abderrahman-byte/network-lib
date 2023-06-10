#include <array>
#include <cstdint>
#include <cstring>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

#include "libnet/Socket.hpp"
#include "libnet/config.hpp"

class SocketTest : public ::testing::Test {
    protected:
        Socket socket;

        void SetUp() override {
            this->socket = Socket(SocketType::tcp);
        }
        
        void TearDown() override {
            if (!this->socket.isClosed()) this->socket.close();
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

    ASSERT_FALSE(socket.isClosed());
}

// Testing socket as echo client
// checkout https://tcpbin.com/

TEST_F(SocketTest, TCPClient) {
    std::string server_ip = "45.79.112.203";
    uint16_t server_port = 4242;
    std::array<std::string, 4> data{ "hello\n", "bro\n", "words\n", "mike\n" };
    char recvbuff[10];

    socket.connect(server_ip, server_port);

    for (int i = 0; i < 4; i++) {
        memset(recvbuff, 0, 10);

        socket.send(data[i].c_str(), data[i].length());
        socket.recv(recvbuff, 10);
        
        EXPECT_EQ(strcmp(recvbuff, data[i].c_str()), 0);
    }

    socket.close();
    
    ASSERT_TRUE(socket.isClosed());
}

TEST(Socket, InvalidSocket) {
    Socket socket;

    EXPECT_FALSE(socket.isValid());
}
