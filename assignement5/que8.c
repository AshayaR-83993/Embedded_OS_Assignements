#include<stdio.h>

int main(){

int a,b,c;

float average;

printf("enter three integer numbers :");

scanf("%d\n%d\n%d",&a,&b,&c);


average = (float)a+b+c/3;


printf("average is : %.2f",average);

return 0;

}
