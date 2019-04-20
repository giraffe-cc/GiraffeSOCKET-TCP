#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Server {
private:
    int listen_sock;
    std::string ip;
    int port;

public:
    Server(const int& port_ , const std::string& ip_)
        :port(port_)
        ,ip(ip_)
        ,listen_sock(-1)
    {}

    void InitServer() {
        listen_sock = socket(AF_INET , SOCK_DGRAM , 0);
        if (listen_sock < 0) {
            std::cerr << "socket failed" << std::endl;
            exit(2);
        }
        struct sockaddr_in local;
        bzero(&local , sizeof(local)); // 把一段内存空间全部清零

        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = inet_addr(ip.c_str());

        if(bind(listen_sock , (struct sockaddr*)&local , sizeof(local)) < 0) {
            std::cerr << "bind failed" << std::endl;
            exit(3);
        }

        if (listen(listen_sock , 5) < 0) {
            std::cerr << "listen failed" << std::endl;
            exit(4);
        }
    }

    void Run() {
        for( ; ; ) {
            
        }
    }

    ~Server() {

    }

};
