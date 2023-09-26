#include <stdio.h>
#include <stdlib.h>

int calculate(int n, int c, int b, int a){
	
	if(n==0) return c;
	
	return calculate(n-1, a+b+c,c,b);
	
}


int main(){
	
	int n = 0;
	
	printf("Please enter term \n");
	scanf("%i",&n);
	
	if(n>3){
		n = n-3;
		printf("Nth term = %i\n",calculate(n,-2,2,1));
	}
	else if(n == 3)printf("Nth term = -2\n");
	else if(n == 2)printf("Nth term = 2\n");
	else if(n == 1)printf("Nth term = 1\n");
	
}

