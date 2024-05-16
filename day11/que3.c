#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
int arr[2];

void sigint_handler(int sig){

	close(arr[1]);
	close(arr[0]);
	_exit(0);
}

int main(){
	char ch ='A';
	int ret,err;
	struct sigaction sa;
	ret = pipe(arr);
	if(ret < 0){
		
		perror("pipe() failed");
		_exit(1);
	}
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	err = sigaction(SIGINT,&sa,NULL);
	if(err < 0){
		
		perror("sigaction failed()");
		_exit(0);
	}

	int count = 0;

	while(1){
		
		write(arr[1],&ch,1);
		count++;
		printf("bytes written : %d\n",count);
	}
	return 0;
}
