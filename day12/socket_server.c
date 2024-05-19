#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include<stdlib.h>
#include<sys/un.h>
#include<signal.h>
//#include <netinet/in.h>
//#include <netinet/ip.h>
//#include <arpa/inet.h>
// server

int serv_fd;

//#define SERV_PORT	2809
//#define SERV_IP		"127.0.0.1"

#define SOCK_PATH "/tmp/desd_sock"
void sigint_handler(int sig){

	shutdown(serv_fd,SHUT_RDWR);
	unlink(SOCK_PATH);
	_exit(0);
}

int main() {
	int cli_fd, ret;
	struct sockaddr_un serv_addr, cli_addr;
	socklen_t socklen;
	int num1,num2,add;

	struct sigaction sa;

	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT,&sa,NULL);
	if(ret < 0){
		perror("sigactio() failed");
		_exit(1);
	}

	serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(serv_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path,SOCK_PATH);
	//serv_addr.sin_port = htons(SERV_PORT);
	//inet_aton(SERV_IP, &serv_addr.sin_addr);
	ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);

	while(1){

		socklen = sizeof(cli_addr);
		cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
		if(cli_fd < 0) {
			perror("accept() failed");
			_exit(3);
		}

		read(cli_fd,&num1, sizeof(num1));
		read(cli_fd,&num2,sizeof(num2));

		//printf("client: %d and %d\n",num1,num2);

		add = num1 + num2;

		printf("server: %d + %d = %d\n",num1,num2,add);

		write(cli_fd, &add, sizeof(add));


		close(cli_fd);
	}
	//shutdown(serv_fd, SHUT_RDWR);
	return 0;
}
