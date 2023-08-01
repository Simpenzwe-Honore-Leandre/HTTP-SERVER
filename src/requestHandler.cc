#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include "requestHandler.h"
void handleRequest(int new_socket_fd)
{
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\nServer's world!";
    long valread;
    char Buffer[30000] = {0};
    valread = recv(new_socket_fd,Buffer,30000,0);
    printf("%s\n",Buffer);
    write(new_socket_fd,hello,strlen(hello));
    printf("\n\n------------------server message sent-------------------\n\n");
    close(new_socket_fd);
    printf("\n\n------------------waiting for new connection-------------------\n\n");

}


