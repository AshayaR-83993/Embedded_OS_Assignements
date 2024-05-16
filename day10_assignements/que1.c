//1. The child process send two numbers to the parent process via message queue.
//The parent process calculate the sum and return via same message queue.
//The child process print the result and exit. The parent process wait for completion of the 
//child and then exit.

#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>
#include<signal.h>
#define MQ_KEY 		0X1234

typedef struct msg1{
	long type;
	int n1;
	int n2;
}msg_t1;

typedef struct msg2{

	long type;
	int add;

}msg_t2;

int main(){
	
	int add,mqid,ret,s,ret1,ret2;
	
	mqid = msgget(MQ_KEY,IPC_CREAT | 0600);
	if(mqid < 0){
	
	perror("msgget() failed ");
	_exit(1);

	}

	ret = fork();
	if(ret == 0){
		
		msg_t1 m1;
//		msg_t1 m2;
		msg_t2 m4;
		m1.type = 1;
		//m1.type = 1;
		printf("sender(child) : enter two numbers :\n");
		scanf("%d%d",&m1.n1,&m1.n2);
		ret1 = msgsnd(mqid,&m1,sizeof(m1.n1)*2,0);
		//ret2 = msgsnd(mqid,&m1,sizeof(m1.n2),0);
		printf("sender(child): message sent : %d\n",ret1);
		printf("sender(child): message sent : %d\n",ret2);
		msgrcv(mqid,&m4,4,2,0);
		printf("add of the two numbers : %d\n",m4.add);

	}

	else{
		msg_t1 m3;
		//msg_t1 m4;
		msg_t2 k;
		k.type=2;
		printf("reciever(parent) : waiting for message...\n");
		ret1 = msgrcv(mqid,&m3,8,1,0);
	//	ret2 = msgrcv(mqid,&m4,sizeof(m4.n2),1,0);
		
		k.add = m3.n1 + m3.n2;

		msgsnd(mqid,&k,4,0);

		printf("reciever(parent) : message recieved 1 : %d ---- %d\n",ret1,m3.n1);
		printf("reciever(parent) : message recieved 2 : %d ---- %d\n",ret2,m3.n2);

		wait(&s);

		msgctl(mqid,IPC_RMID,NULL);
	}
	return 0;
}

