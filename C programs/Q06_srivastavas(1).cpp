#include <stdio.h>
#include <stdlib.h>

int value(int a, int d, int i){
	
	if(i != 0){
		
		value(a+d,d,i-1);
	}
	else return a;
}

int main (){
	
	int A = 0;
	int D = 0;
	int i = 0;
	
	printf("Please enter A \n");
	scanf("%i",&A);
	
	printf("Please enter D \n");
	scanf("%i",&D);
	
	printf("Please enter term\n");
	scanf("%i",&i);
	
	printf("Answer is %i",value(A, D, i));
	
}
