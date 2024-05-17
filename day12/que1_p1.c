//1. The client process send two numbers to the server process via one ﬁfo. 
//The server process calculate the sum and return via another ﬁfo. The client
//process print the result.

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1,fd2,cnt1,cnt2;
	int num1,num2,add;

	fd1 = open("/tmp/addition",O_WRONLY);
	if(fd1 < 0){
		perror("open() failed");
		_exit(1);
	}

	printf("enter two numbers : \n");
	scanf("%d %d",&num1,&num2);

	cnt1 = write(fd1,&num1,sizeof(num1));
	cnt2 = write(fd1,&num2,sizeof(num2));

	printf("written in fifo : %ld bytes\n",(sizeof(num1)+sizeof(num2)));
	
	fd2 = open("/tmp/add",O_RDONLY);
	if(fd2 < 0 ){
		
		perror("read(p1) : open() failed");
		_exit(2);

	}

	int addition = read(fd2,&add,sizeof(add));

	printf("read in p1 : addition is : %d\n",add);

	close(fd1);
	close(fd2);

	return 0;
}
