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
	
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	
	printf("recieved message: %s", message.msg_text);
	
	msgctl(msgid, IPC_RMID, NULL);
	
}
