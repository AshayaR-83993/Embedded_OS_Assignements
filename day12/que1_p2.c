#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd1,fd2,cnt1,cnt2;
	int num1,num2,add;

	fd1 = open("/tmp/addition",O_RDONLY);
	if(fd1 < 0){
		
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for message...\n");
	cnt1 = read(fd1,&num1,sizeof(num1));
	cnt2 = read(fd1,&num2,sizeof(num2));

	printf("read from fifo : %ld bytes --- %d and %d\n",(sizeof(num1)+sizeof(num2)),num1,num2);
	
	fd2 = open("/tmp/add",O_WRONLY);
	if(fd2 < 0){

		perror("write(p2) : open() failed");
		_exit(2);
	}

	add = num1 + num2;

	printf("additon : %d\n",add);

	int addition = write(fd2,&add,sizeof(add));

	printf("written in p2 : addition sent : %d bytes\n",sizeof(add));
	
	close(fd1);
	close(fd2);

	return 0;
}
