#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<string>
#include<string.h>
#define PORT 8080
#define SOCKET_INIT_ERROR "Socket creation failed!"
#define BIND_ERROR "Bind failed!"
int main(int argc,char const *argv[])
{
    int socket_fd;
    long valread;
    struct sockaddr_in address;
    std::string hello = "Hello from client!";
    char Buffer[1024] = {0};

    if((socket_fd = socket(AF_INET,SOCK_STREAM,0))< 0)
    {
        perror(SOCKET_INIT_ERROR);
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    // address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(address.sin_zero,'\0',sizeof(address.sin_zero));

    if(inet_pton(AF_INET,"127.0.0.1",&address.sin_addr) <= 0)
    {
        perror("inet_pton error, Address not supported");
        exit(EXIT_FAILURE);
    }

    if(connect(socket_fd,(struct sockaddr *)&address,sizeof(address))<0)
    {
        perror("Connection failed!");
        exit(EXIT_FAILURE);
    }

    send(socket_fd,hello.c_str(),sizeof(hello),0);
    printf("client message sent!\n");    
    valread = recv(socket_fd,Buffer,1024,0);
    printf("%s\n",Buffer);
    return 0;

}