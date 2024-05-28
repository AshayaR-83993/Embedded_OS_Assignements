#include<stdio.h>

int main(){

float c,f;

printf("enter a number to convert from farhenite to celsius\n");
scanf("%f",&f);

c = (float)5/9*(f-32);

printf("conversion to celsius is : %f",c);

printf("enter a number to convert from celsius to farhenite\n");
scanf("%f",&c);

f = ((float)9/5*c)+32;

printf("conversion to farhenite is : %f",f);

return 0;

}

