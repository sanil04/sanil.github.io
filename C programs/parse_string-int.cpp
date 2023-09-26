#include <stdio.h>
#include <stdlib.h>
/*
	In this small program you will parse an n-tuple.
	A valid n-tuple can have up to a maximum of 10 coordinates.
	Each coordinate can have up to a max of 9 digits.
	A valid n-tuple can have any number of leading spaces
	A valid n-tuple can have any number of trailing spaces
*/


#define MAX_COORDS 10
#define MAX_DIGITS_PER_COORD 9

typedef struct {
	int coords[MAX_COORDS];
	int n;	// number of coordininates in n-tuple
	// if n = 3 the point is in the 3rd dimension
}nTupleType;


int parseNTuple (char *nts, nTupleType *nT){
	
	nT->n=0;	
	int z = 0;
	int i = 0;
	
	
	
	while(nts[i]== ' ')i++;
	
		if(nts[i]!= '(') return 0 ;
		i++;
		
		while(nts[i]!=')'){
			
				
			if(nts[i]<'0'&&nts[i]>'9'&&nts[i]!='-')return 0;
			if(nts[i]=='-'&& nts[i+1]==0) return 0;
			
			
			nT->coords[nT->n]= atoi(&nts[i]);//line added
			
			if(nts[i]== '-')i++;
	
			z = i;
			
			
			if(nts[z]=='0'&& nts[z+1]!=',')return 0;
			
			while(nts[z]>='0'&&nts[z]<='9')z++;
			if((z-i)>9)return 0;
			
			if(nts[z]!= ','&&nts[z]!= ')')return 0;
			
			nT->n++;
			i = z;
			if(nts[i]== ')')i--;
			i++;
			if (nT->n>10)return 0;
			
		}
		
		i++;
		
		while(nts[i]){
			
			if(nts[i] !=' '){
				
				return 0;
			}
			i++;
		}
		
		
			
		return 1;
		
		
}
//output function added
void outputNTuple (nTupleType nT){
	
	int j = 1;
	
	for(int i = 0; i< nT.n; i++){
		
		printf("The coordinate in dimesion %i = %i\n",j ,nT.coords[i]);
		j++;
	}	
}

int main (){
	int i = 5;
	char nTupString[100] = "  (-34242,433,0,-353,9821,8,5)   ";
	// leading a trailing space ok ... but no other spaces
	nTupleType nT;
	
	if (parseNTuple (nTupString,&nT)){
		
		printf ("Here is your valid nTuple:  \n");
		outputNTuple (nT);//line added
		
	}
	else{
		printf ("\"%s\" is an invalid nTuple String.\n\n",nTupString);
	}
	
	
	
}
