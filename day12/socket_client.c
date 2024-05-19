//2. Create a server that accept multiple clients connected over UNIX sockets. 
//Each client send two numbers, server do the addition and send the result back.
//The client connection should be closed immediately after sending response.
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
//#include<sys/wait.h>
//#include<netinet/in.h>
//#include<netinet/ip.h>
//#include<arpa/inet.h>

//#define SERV_PORT 1234
//#define SERV_IP "172.18.5.129"

#define SOCK_PATH "/tmp/desd_sock"

int main(){
	
	int cli_fd,ret;
	struct sockaddr_un serv_addr;
	int num1,num2,add;
	socklen_t socklen;

	cli_fd = socket(AF_UNIX,SOCK_STREAM,0);
	if(cli_fd < 0){
		
		perror("socket() failed");
		_Exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path,SOCK_PATH);
	//serv_addr.sin_port = htons(SERV_PORT);
	//inet_aton(SERV_IP,&serv_addr.sin_addr);
	ret = connect(cli_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret < 0 ){
		
		perror("connect() failed");
		_Exit(2);
	}

	//do{
		//while(1){

		printf("client :");
		printf("enter two numbers : \n");
		scanf("%d %d",&num1,&num2);

		write(cli_fd,&num1,sizeof(num1));
		write(cli_fd,&num2,sizeof(num2));
		
		//add = num1 + num2;

		read(cli_fd,&add,sizeof(add));
		printf("server : %d\n",add);
	//}while(strcmp(str,"bye") != 0);

	close(cli_fd);
	
	return 0; 
}
