#include <stdio.h>

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
	int neg = 0;
	
	while(nts[i]== ' ')i++;
	
		if(nts[i]!= '(')return 0,printf("1");
		i++;
		
		while(nts[i]!=')'){
			
			if(nts[i]!='0'-'9'||'-')return 0,printf("2");
			if(nts[i]=='-'&& nts[i+1]==0) return 0,printf("3");
			if(nts[i]== '-')i++, neg = 1;
			z == i;
			if(nts[z]=='0'&& nts[z+1]!=',')return 0,printf("4");
			while(nts[z]=='0'-'9')z++;
			if((z-i)>9)return 0,printf("5");
			if(nts[z]!= ',')return 0,printf("6");
			nT->n++;
			i == z;
			i++;
			if (nT->n>10)return 0,printf("7");
		}
		i++;
		while(nts[i]==' '||'\0'){
			if(nts[i] == '\0')return 1;
			if(nts[i] !=' ')return 0,printf("8");
			i++;
		}
}



/*void outputNTuple (nTupleType nTuple){
}
*/


int main (){
	char nTupString[100] = "     (-34242,4353,0,-3535,9821,8)   ";
	// leading a trailing space ok ... but no other spaces
	nTupleType nT;
	/*
	if (parseNTuple (nTupString,&nT)){
		printf ("Here is your nTuple ...\n");
		outputNTuple (nTuple);
	}
	else{
		printf ("\"%s\" is an invalid nTuple String.\n\n",nTupString);
	}
	*/
	
	parseNTuple(nTupString,&nT);
	
}
