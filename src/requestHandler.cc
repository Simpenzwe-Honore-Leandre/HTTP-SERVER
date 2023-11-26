#include<unistd.h>
#include<stdio.h>
#include<string>
#include<sys/socket.h>
#include "requestHandler.h"
void handleRequest(const int &new_socket_fd)
{
    std::string hello = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\nConnection: close\r\n\r\nHello world!";
    long long valread;
    char Buffer[1024] = {0};
    valread = recv(new_socket_fd,Buffer,1024,0);
    // request_struct *request;
    // http_parse(Buffer, request);
    printf("%s\n",Buffer);
    send(new_socket_fd,hello.c_str(),hello.length(),0);
    printf("\n\n------------------server message sent-------------------\n\n");
    close(new_socket_fd);
    printf("\n\n------------------waiting for new connection-------------------\n\n");

}


