#include <stdio.h>
#include <stdlib.h>

int charCount(int i,int z,char *A, char B){

	
	if (A[z] == '\0'){
		return i;
	}
	if (A[z] == B) return charCount(i+1,z+1,A,B);
	if (A[z] != B) return charCount(i,z+1,A,B);

	
}



int main(){
	
	int i = 0;
	int z = 0;
	int g = 0;
	char A[10];
	char B;
	
	printf("Please enter a string under 10 characters\n");
	gets(A);
	
	printf("Please enter the character\n");
	scanf("%c",&B);
		
	printf("String = %s\n",A);
	printf("Character = %c\n",B);
	
	g = charCount(i,z,A,B);
	
	printf("# of chars = %i",g);
} 
