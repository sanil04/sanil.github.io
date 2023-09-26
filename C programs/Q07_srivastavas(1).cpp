#include <stdio.h>
#include <stdlib.h>

int value(int A, int R, int i){
	if(i != 0){
		
		value(A*R,R,i-1);
		
	}
	else return A;
	
}

int main (){
	
	int A = 0;
	int R = 0;
	int i = 0;
	
	printf("Please enter A \n");
	scanf("%i",&A);
	
	printf("Please enter R \n");
	scanf("%i",&R);
	
	printf("Please enter term\n");
	scanf("%i",&i);
	
	printf("Answer is %i",value(A, R, i));
	
}
