#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void main()
{
    int sockfd, connfd1, connfd2, len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed.\n");
        exit(0);
    }
    else
        printf("Socket successfully created.\n");

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("Socket bind failed.\n");
        exit(0);
    }
    else
        printf("Socket successfully binded.\n");

    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed.\n");
        exit(0);
    }
    else
        printf("Server listening.\n");

    len = sizeof(cli);

    char buf1[100], buf2[100];
    
    connfd1 = accept(sockfd, (SA *)&cli, &len);
    connfd2 = accept(sockfd, (SA *)&cli, &len);

    if (connfd1 < 0 || connfd2 < 0)
    {
        printf("Connection with clients failed.\n");
        exit(0);
    }
    else
        printf("Connection created with clients successfully.\n");

    while (1)
    {
        read(connfd1, buf1, sizeof(buf1));      
        read(connfd2, buf2, sizeof(buf2));          
        printf("Message from client 1: %s\n", buf1); 
        printf("Message from client 2: %s\n", buf2); 
        write(connfd1, buf2, sizeof(buf2));
        write(connfd2, buf1, sizeof(buf1));
    }

    close(sockfd);
}

