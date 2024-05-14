//3. Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). 
//Compile the program using "gcc" and execute it. No fork(), exec() expected here.
//Compilation commands:
//gcc -c circle.c
//gcc -c square.c
//gcc -c rectangle.c
//gcc -c main.c
//Linking command:
//gcc -o program.out circle.o square.o rectangle.o main.o
//Execute command:
//./program.out

#include<stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main(){
//int r = 7;
int area = circleArea(7);
printf("Area of circle = %d\n" , area);

//int a = 10;
int square_area = squareArea(10);
printf("Area of square = %d\n",square_area);

int rectangle_area = rectangleArea(10,20);
printf("area of rectangle = %d\n",rectangle_area);

return 0;
}
