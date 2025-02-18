#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	printf("\n Searching for server....\n");
	struct sockaddr_in servaddr;
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(8080);
	servaddr.sin_addr.s_addr=INADDR_ANY;
	int n=-1;
	sendto(sockfd,&n,sizeof(n),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	printf("\nServer connected successfully\n");
	printf("\nEnter the total no of frames:");
	scanf("%d",&n);
	sendto(sockfd,&n,sizeof(n),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	int len,ack;
	for(int i=1;i<=n;i++){
		ack=-1;
		do{
			printf("\nSending frames:%d",i);
			sendto(sockfd,&i,sizeof(n),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
			printf("\nWaiing for Ack....\n ");
			recvfrom(sockfd,&ack,sizeof(n),0,(struct sockaddr *)&servaddr,&len);
			if(ack==-1)
				printf("\nNegative ack received... Resending...\n");
		}while(ack==-1);
	}
	n=-99;
	sendto(sockfd,&n,sizeof(n),0,(const struct sockaddr *)&servaddr,sizeof(servaddr));
	printf("\n Successfully sent all the frames\n");
	close(sockfd);
	return 0;
}

