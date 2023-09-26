#include <stdio.h>
#include <stdlib.h>

#define MIN_NAME_CHARS 3
#define MAX_NAME_CHARS 10
#define MIN_NAME_CHAR 'a'
#define MAX_NAME_CHAR 'z'
#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 30
#define MIN_YEAR 1980
#define MAX_YEAR 2000
#define MIN_SALARY 20000
#define MAX_SALARY 500000


typedef struct {
	int day, month,year;
} dateType;

typedef struct {
	char lName[MAX_NAME_CHARS + 1];
	dateType dob;
} empType;



int parseEmps(empType *emps, int n){
	
	int i = 0;
	int j = 0;
	
	char emp[100];
	
	printf("Please enter employee \n" );
	scanf("%s",emp);
	
	
	//while(emp[i] == ' ')i++;
	
	//printf("i = %i\n",i);
	
	if(emp[i] < MIN_NAME_CHAR || emp[i] > MAX_NAME_CHAR){
	printf("1\n");
	 return 0; //lname
	}
	
	while(emp[i]>=MIN_NAME_CHAR&&emp[i]<=MAX_NAME_CHAR)i++;
	if((i)>MAX_NAME_CHARS || (i)<MIN_NAME_CHARS){
	printf("2\n");
	 return 0;}
	
	j = i;

	//printf("i-j = %i\n",i-j);
	
	if(emp[i] != ','){
	printf("3\n");
	 return 0;}
	i++;
	
	
	
	for(i = 0;i<j;i++){
		emps[0].lName[i] = emp[i];
	}
	
	i = j+1;
	
	emps[0].dob.day = atoi(&emp[i]);
	
	while(emp[i] != ',')i++;
	i++;
	
	emps[0].dob.month = atoi(&emp[i]);
	
	while(emp[i] != ',')i++;
	i++;
	
	emps[0].dob.year = atoi(&emp[i]);
	
	return 1;
}

void getEmpsFromUser(empType *emps, int n){
	
	int j = 1;
	
	while(j){ 
		if (parseEmps(emps, n)){
		//printf("1\n");
		j = 0;
		}
		else{
			printf("invalid input\n");
		}
	}

}
void outputEmps(empType *emps, int n){
	
	for (int i=0;i<n;i++){
		
		printf("lastname = %s ",emps[i].lName);
		printf("day = %i ",emps[i].dob.day);
		printf("month = %i ",emps[i].dob.month);
		printf("year = %i \n",emps[i].dob.year);
	}
}

int main (){
	empType emps[1000];
	int numEmps = 3;		// not getting this from user … i gave it to you
	char empString [400];		// won’t overflow this … I hope


	
	// now get this many employees from the user
	// getEmpsFromUser will be tough
	// sortEmpsByDOB will be easier
	// outputEmps will be easy … just output one emp per line comma delimited with no spaces
	for (int i = 0; i < numEmps; i++){
		getEmpsFromUser(emps, numEmps);	// you write this
		//sortEmpsByDOB(emps, numEmps);		// you write this .. young to old
		outputEmps (emps, numEmps);		// you write this
	}
	
}




