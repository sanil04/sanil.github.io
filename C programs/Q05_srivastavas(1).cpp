#include <stdio.h>
#include <stdlib.h>

int sum(int *A, int min, int max, int i){
	
	if(min <= max){
		
		sum(A, min+1, max, i+A[min]);
		
	}
	else return i;
	
}


int main (){
	
	int A[10] = {3,23,54,23,121,9,1,6,98,2};
	int min = 0;
	int max = 0;
	int i = 0;
	int z = 0;
	
	printf("Enter min>=0 \n");
	scanf("%i",&min);
	printf("Enter max<10 \n");
	scanf("%i",&max);
	
	z = sum(A, min, max, i);
	
	printf("Sum = %i", z);
	
}


