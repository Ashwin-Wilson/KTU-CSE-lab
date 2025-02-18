#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int isfaulty(){
	int d=rand()%4;
	return (d>2);
}

int main() {
	srand(time(0));
	int c_sock;
	c_sock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in client;
	memset(&client, 0, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_port = htons(9009);
	client.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(connect(c_sock, (struct sockaddr*)&client, sizeof(client)) == -1) {
		printf("Connection failed");
		return 0;
	}
	printf("\n\tClient -with individual acknowledgement scheme\n\n");
	char msg1[50]="acknowledgement of";
	char msg3[50]="negative ack ";
	char msg2[50];
	char buff[100];
	int count=-1,flag=1;
	while(count<8){
	bzero(buff,sizeof(buff));
	bzero(msg2,sizeof(msg2));
	if(count==7&&flag==1){
		printf("here\n");
		flag=0;
		read(c_sock,buff,sizeof(buff));
		continue;
	}
	int n = read(c_sock, buff, sizeof(buff));
	char i=buff[strlen(buff)-1];
	printf("Message received from server : %s \n",buff);
	int isfault=isfaulty();
	printf("corruption status : %d \n",isfault);
	printf("Response/acknowledgement sent for message \n");
	if(isfault)
	strcpy(msg2,msg3);
	else{
	strcpy(msg2,msg1);
	count++;}
	msg2[strlen(msg2)]=i;
	write(c_sock,msg2, sizeof(msg2));
	}
	close(c_sock);
	
	return 0;
}

