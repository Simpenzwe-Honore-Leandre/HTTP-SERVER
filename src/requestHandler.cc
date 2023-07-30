#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include "requestHandler.h"
void handleRequest(int new_socket_fd)
{
    char *hello = "Hello from server!";
    long valread;
    char Buffer[30000] = {0};
    valread = read(new_socket_fd,Buffer,30000);
    printf("%s\n",Buffer);
    write(new_socket_fd,Buffer,strlen(hello));
    printf("------------------Hello message sent-------------------");
    close(new_socket_fd);
}


#endif