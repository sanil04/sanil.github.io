#include <stdio.h>
#include <stdlib.h>

void reverse(int max, int min, char *A){
	char temp;
	
	if(max>min){
		
		
		temp = A[min];
		A[min] = A[max];
		A[max] = temp;
		
		reverse(max-1,min+1,A);
	}
	
	
}

int length(int i, char *A){
	
	if(A[i] == '\0') return i;
	length(i+1,A);
}

int main(){
	
	char A[10];
	int min = 0;
	int max = 0;
	
	printf("Please enter a string under 10 characters\n");
	gets(A);
	printf("Original = %s\n",A);
	
	max = (length(min,A))-1;
	


	min = 0;
	
	reverse(max, min,A);
	
	printf("Reversed = %s\n",A);
	
}
