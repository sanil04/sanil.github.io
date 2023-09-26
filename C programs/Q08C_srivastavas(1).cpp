#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int n = 0;
	int c = -2;
	int b = 2;
	int a = 1;
	int temp = 0;
	
	printf("Please enter term \n");
	scanf("%i",&n);
	
	if(n>3){
		n = n-3;
		
		while(n!=0){
			
			temp = c;
			c = a+b+c;
			a = b;
			b = temp;
			n--;
			
		}
		printf("Nth term = %i\n",c);
		
	}
	else if(n == 3)printf("Nth term = -2\n");
	else if(n == 2)printf("Nth term = 2\n");
	else if(n == 1)printf("Nth term = 1\n");
	
}
