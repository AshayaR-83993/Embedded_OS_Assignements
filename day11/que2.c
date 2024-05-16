#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int arr1[2],arr2[2];
	int num1,num2,n1,n2,ret,s;
	int res;
	ret = pipe(arr1);
	ret = pipe(arr2);
	ret = fork();
	if(ret == 0 ){
		
		close(arr1[0]);
		close(arr2[1]);
		printf("enter two numbeers :\n");
		scanf("%d %d",&num1,&num2);
		write(arr1[1],&num1,sizeof(num1));
		write(arr1[1],&num2,sizeof(num2));

		read(arr2[0],&res,sizeof(res));
		printf("result : %d\n",res);
		close(arr1[1]);
		close(arr2[0]);
	}	

	else{

		close(arr1[1]);
		close(arr2[0]);
		read(arr1[0],&n1,sizeof(n1));
		read(arr1[0],&n2,sizeof(n2));

		res = n1 + n2;

		write(arr2[1],&res,sizeof(res));

		close(arr2[1]);
		close(arr1[0]);
		waitpid(-1,&s,0);
	}
	return 0;
}

