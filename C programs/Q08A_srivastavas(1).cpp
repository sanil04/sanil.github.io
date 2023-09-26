#include <stdio.h>
#include <stdlib.h>

int calculate(int n){
	
	if(n == 1)return 1;
	if(n == 2)return 2;
	if(n == 3)return -2;
	
	return calculate(n-1)+calculate(n-2)+calculate(n-3);
}


int main(){
	
	int n = 0;
	
	printf("Please enter term \n");
	scanf("%i",&n);
	
	printf("Nth term = %i\n",calculate(n));
	}
