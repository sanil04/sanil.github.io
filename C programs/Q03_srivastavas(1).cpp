#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int min = 0;
	int max = 0;
	
	
	printf("Enter min \n");
	scanf("%i",&min);
	printf("Enter max \n");
	scanf("%i",&max);
	
	printf("Sum = %i\n",((max-min+1)*(min+max))/2);
}

