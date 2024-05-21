#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	int i,ret1,ret2,ret3,ret4,s1,s2,s3,s4,s5,s6,err,s;
	printf("parent started !!!\n");

	ret1 = fork();
	if(ret1 == 0 ){
		
		char *args[] = {"gcc","-c","circle.c",NULL};
		err = execvp("gcc",args);
		if(err < 0){
			
			perror("exec() failed");
			_exit(1);
		}

		printf("circle.c is compiled through child1");
		}
	
	ret2 = fork();
	if(ret2 == 0){

		 
		char *args[] = {"gcc","-c","square.c",NULL};
		err = execvp("gcc",args);
		if(err < 0){
			
			perror("exec() failed");
			_exit(1);
		}
		
		printf("square.c is compiled through child1");
	}

	
	ret3 = fork();
	if(ret3 == 0){

		 
		char *args[] = {"gcc","-c","rectangle.c",NULL};
		err = execvp("gcc",args);
		if(err < 0){
			
			perror("exec() failed");
			_exit(1);
		}
		printf("rectangle.c is compiled through child3");

	}

	ret4 = fork();
	if(ret4 == 0){

		 
		char *args[] = {"gcc","-c","main.c",NULL};
		err = execvp("gcc",args);
		if(err < 0){
			
			perror("exec() failed");
			_exit(1);
		}
		printf("main.c is compiled through child4");

	}

	int ret5 = fork();
	if(ret5 == 0 ){
		
		char *args[] = {"gcc","-o","program.out","circle.o","square.o","rectangle.o","main.o",NULL};
		err = execvp("gcc",args);
		if(err < 0 ){
		
			perror("exec() failed");
			_exit(1);
		}

		printf("all files linked using child5");
	}

	int ret6 = fork();
	if(ret6 == 0 ){
		
			char *args[] = {"./program.out",NULL};
			err = execvp("/home/ashay/Desktop/EOS_ASSIGNEMENTS/Day09_assignements/que4/program.out",args);
			if(err < 0){

				perror("exec() failed");
				_exit(1);
			}
	}


	else{

			waitpid(ret1,&s1,0);
			waitpid(ret2,&s2,0);
			waitpid(ret3,&s3,0);
			waitpid(ret4,&s4,0);
			waitpid(ret5,&s5,0);
			waitpid(ret6,&s6,0);
			if(s1 != 0 || s2 != 0 || s3 != 0 || s4 != 0 || s5 != 0 || s6 != 0){
	
					printf("compiler errors \n");
					_exit(1);
			}

			//printf("child exit status : %d\n",WEXITSTATUS(s));

	}
	printf("parent completed \n");
	printf("bye bye !!!");
	return 0;
}
