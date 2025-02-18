#include <stdio.h>
#include <sys/socket.h>
#include<sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 4000


void main(){
	int m,n=100,sockfd,addr=sizeof(struct sockaddr_in);
	char buf[1025];
	struct sockaddr_in y;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	y.sin_family=AF_INET;
	y.sin_port=htons(PORT);
	y.sin_addr.s_addr=htonl(INADDR_ANY);
	printf("connecting....\n");
	while(1){
		printf("msg to be send :");
		scanf("%s",buf);
		sendto(sockfd,buf,n,0,(struct sockaddr*)&y,addr);
		if(strcmp(buf,"quit")==0)
			break;
		printf("msg send \n waiting for the response\n");
		n=recvfrom(sockfd,buf,1024,0,(struct sockaddr*)&y,&addr);
		buf[n]='0';
		if(n>1)
			printf("\n received :%s \n",buf);
	}
	close(sockfd);
}
