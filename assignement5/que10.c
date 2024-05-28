#include<stdio.h>
#include<math.h>

int main(){

float a,b,c,area,perimeter;

printf("enter the length for sides of triangle :");
scanf("%f%f%f",&a,&b,&c);

perimeter = a+b+c;

float s = (a+b+c)/2; //s is semiperimeter

area = sqrt(s*(s-a)*(s-b)*(s-c));

printf("perimeter is %.2f\n ",perimeter);

printf("semiperimeter is  %.2f\n",s);

printf("area is %.2f",area);

return 0;

}


