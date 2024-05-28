#include<stdio.h>

int main(){

int a,b,c,d,e,num;

printf("enter a four digit number :\n");
scanf("%d",&num);

e = num;

a = num/1000;
num = num%1000;

b = num/100;
num = num%100;

c = num/10;
num = num%10;

d = num;

printf("%d\t%d\t%d\t%d\n",a,b,c,d);

printf("%d = %d + %d + %d + %d\n",e,(a*1000),(b*100),(c*10),d);

printf("%d%d%d%d\n",d,c,b,a);

return 0;

}
