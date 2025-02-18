#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include <unistd.h>

#define PORT 4000
int main(){
	int n,sockfd,addr=sizeof(struct sockaddr_in);
	char buf[1024];
	struct sockaddr_in x;
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
		printf("error in creating socket \n");
	else
		printf("socket successfully created\n");
	x.sin_family=AF_INET;
	x.sin_port=htons(PORT);
	x.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(sockfd,(struct sockaddr*)&x,sizeof(x));
	printf("waiting...\n");
	do{
		n=recvfrom(sockfd,buf,1024,0,(struct sockaddr*)&x,&addr);
		buf[n]='\0';
		if(n>1)
			printf("received : %s \n",buf);
		scanf("%s",buf);
		sendto(sockfd,buf,n,0,(struct sockaddr*)&x,addr);
	}while(strcmp(buf,"quit")!=0);
	close(sockfd);
}
