#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

//1. From one parent create 5 child processes. Each child should run for 5 seconds and 
//print count along with its pid. Parent should wait for all child processes
//to complete and clean all of them. Hint: use loop to fork() multiple child processes.

int main(){

	int ret,i,s,count;
	for(i=1;i<=5;i++){
		ret = fork();
		if(ret == 0){
			for(int j=1;j<=5;j++){
				printf("child : %d , count : %d , child_pid : %d\n",i,j,getpid());
				sleep(1);
			}
			//sleep(1);
			_exit(0);
		}
	}

	//else{

	for(int j =1;j<=5;j++){
		printf("parent : %d\n",j);
		sleep(1);
	}

	for(i=1;i<=5;i++){
		waitpid(-1,&s,0);
		printf("child %d exit : %d , count : %d\n",i,WEXITSTATUS(s),i);
	}
	//}


	return 0;
}

