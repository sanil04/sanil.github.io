#include <stdio.h>
#include <stdlib.h>

int sumNum( int i, int min, int max){
	
	if (min == max+1) return i;
	
	sumNum(i+min,min+1,max);
	
}


int main (){
	
	int min = 0;
	int max = 0;
	int i = 0;
	int g = 0;
	
	printf("Enter min \n");
	scanf("%i",&min);
	printf("Enter max \n");
	scanf("%i",&max);
	
	g = sumNum(i, min, max);
	
	printf("Min = %i\n",min);
	printf("Max = %i\n",max);
	printf("Sum = %i\n",g);
	
}
