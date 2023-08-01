#include<condition_variable>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "requestHandler.h"
#include "ThreadPool.h"
#include<iostream>
#include<thread>

#define PORT 8080
#define SOCKET_INIT_ERROR "Socket creation failed!"
#define BIND_ERROR "Bind failed!"
#define LISTEN_ERROR "Listen failed!"
#define ACCEPT_ERROR "Accept failed!"

int main(int argc, char const *argv[])
{   
    int num_threads;
    if((num_threads = std::thread::hardware_concurrency()) == 0)
    {
        num_threads = 1;
    }
    if(num_threads > 2)
    {
        num_threads = 2;
    }
    ThreadPool thread_pool(num_threads);
    int socket_fd, new_socket_fd;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("%d",socket_fd);
        perror(SOCKET_INIT_ERROR);
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(address.sin_zero,'\0',sizeof(address.sin_zero));

    if(bind(socket_fd,(struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror(BIND_ERROR);
        exit(EXIT_FAILURE);
    }


    if(listen(socket_fd,10) < 0)
    {
        perror(LISTEN_ERROR);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port: %d\n",PORT);
    while(true)
    {   
        //a new socket used by connecting client is returned 
        //accept populates address field with client's address
        if((new_socket_fd = accept(socket_fd,(struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror(ACCEPT_ERROR);
            exit(EXIT_FAILURE);
        }
        thread_pool.queueWork([new_socket_fd]
        {
            handleRequest(new_socket_fd);
        });


    }
    // std::cout<<"Server is listening on port: "<<PORT<<std::endl;
    return 0;
    

}