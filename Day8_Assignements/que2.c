//From a parent process (A) create a child process (B). The child (B) in turn creates new 
//child process (C) and it (C) in turn create new child (D). All these
//processes should run concurrently for 5 seconds and cleaned up properly upon termination.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int retA,retB,retC,retD,i,s;

	retA = fork();
	if(retA == 0){
		retB = fork();
		if(retB == 0){
			retC = fork();
			if(retC == 0){
				retD = fork();
				if(retD == 0){

					printf("inside child D \n");
					//printf("parent status = %d \n",WEXITSTATUS(s));
					_exit(0);
				}

				printf("inside child C \n");
				waitpid(retD,&s,0);
				printf("child status = %d \n",WEXITSTATUS(s));
				_exit(0);
			}

			printf("inside child B \n");
			waitpid(retC,&s,0);
			printf("child status = %d \n",WEXITSTATUS(s));
			_exit(0);
		}

		printf("inside child A \n");
		waitpid(retB,&s,0);
		printf("child status = %d \n",WEXITSTATUS(s));
		_exit(0);

	}

	printf("inside parent \n");
	waitpid(retA,&s,0);
	printf("child status = %d \n",WEXITSTATUS(s));

	return 0;

	}
