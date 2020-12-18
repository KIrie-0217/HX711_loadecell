#ifndef server_C_h
#define server_C_h


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include<iostream>



//class
class server_C{
    public:
        void init();
        void set_port(int port_number);
        void set_host(std::string host_number);
        void start();
        char buf[1024];
        
    private:
        int sockfd;
        int client_sockfd;
        struct sockaddr_in addr;
        socklen_t len;
        struct sockaddr_in from_addr;

        std::string port_number;
        std::string host_number;
        int rsize;
        int flag;
        int num;
        std::string out[27];
        double outnum[27];
};


#endif