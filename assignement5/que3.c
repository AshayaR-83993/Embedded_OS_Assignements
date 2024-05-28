#include<stdio.h>

int main(){

char c;

printf("enter a character :\n");
scanf("%c",&c);

printf("decimal : %d\n",c);

printf("hexadecimal : %x\n",c);

printf("octal : %o\n",c);

int n;

printf("enter a ascii value to print its character :\n");
scanf("%d",&n);

printf("conversion of ascii value to character is :%c\n",n);

return 0;

}
