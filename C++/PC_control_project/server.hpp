#ifndef SERVER_HPP
#define SERVER_HPP
#include <iostream>
#include <string>
#include <array>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include <cstring>
#include <algorithm>

class serverhandel
{
private:
    int socket_init;
    int client_socket_state;
    std::array<char, 1024> text_recv;

public:
    serverhandel(); 
    ~serverhandel();

    bool server_init();
    bool server_listen();
    bool server_accept_client();
    std::string server_recv_client_msg();
    bool server_send_msg(const std::string &message);
    void trim_end(std::string &str);
    void server_close();
    // void close_listening();
    // void close_listening_client();
};

#endif
