#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include<iostream>

#include "server_C.h"

int main(){
    server_C cl;

    cl.init();
    cl.set_port(51001);
    cl.set_host("127.0.0.1");
    cl.start();

}