//1. Input signal number and a process id from user. Send given signal to the given process 
//using kill() syscall.

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

int main(){

	int sig_num,pid,ret;

	printf("enter signal number and process id : \n");
	scanf("%d %d",&sig_num,&pid);

	printf("signal number is %d and pid is %d\n",sig_num,pid);

	ret = kill(pid,sig_num);
	if(ret == 0){
		printf("kill sucessfull \n");
	}
	else
		printf("kill failed \n");

	return 0;
}
