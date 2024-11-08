#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuff{
	long msg_type;
	char msg_text[100];
}message;

void main(){

	key_t key = ftok("progfile", 65);

	int msgid = msgget(key, 0666 | IPC_CREAT);
	
	message.msg_type = 1;
	
	printf("Enter the message: ");	
	
	fgets(message.msg_text, 100, stdin);
	
	msgsnd(msgid, &message, sizeof(message), 0);
	printf("Message sent successfully ");	
	
}
