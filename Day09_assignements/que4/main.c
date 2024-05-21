#include<stdio.h>
#include "circle.h"
#include "rectangle.h"
#include "square.h"

int main(){

	int r=10,a=10,w=10,l=10;
	
	printf("area of circle : %d\n",circlearea(r));
	printf("area of square : %d\n",squarearea(a));
	printf("area of rectangle : %d\n",rectanglearea(w,l));

	return 0;
}
