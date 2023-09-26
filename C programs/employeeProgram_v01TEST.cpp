#include <stdio.h>
#include <stdlib.h>

#define MIN_NAME_CHARS 3
#define MAX_NAME_CHARS 10
#define MIN_NAME_CHAR 'a'
#define MAX_NAME_CHAR 'z'
#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_YEAR 1980
#define MAX_YEAR 2000
#define MIN_SALARY 20000
#define MAX_SALARY 500000

typedef struct {
	int day;
	int month;
	int year;
} dateType;

typedef struct {
	char lName[MAX_NAME_CHARS + 1];
	char mName[MAX_NAME_CHARS + 1];
	char fName[MAX_NAME_CHARS + 1];
	char gender;
	dateType dob;
	int salary;
} empType;


// return 1 if the parsing was a success
// return 0 if the parsing was unsuccessful ... see emp string requirements
int parseEmp(char *s, empType *emps){
	// your code starts here
	
	int i = 0;
	int j = 0;
	int d = 0;
	int m = 0;
	int y = 0;
	int e = 0;
	
	
	while(s[i] == ' ')i++;
	j = i;
	while(s[i]<=MAX_NAME_CHAR && s[i]>=MIN_NAME_CHAR)i++;
	if((i-j)>MAX_NAME_CHARS || (i-j)<MIN_NAME_CHARS)return 0;
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;
	
	while(s[i] == ' ')i++;
	j = i;
	while(s[i]<=MAX_NAME_CHAR && s[i]>=MIN_NAME_CHAR)i++;
	if((i-j)>MAX_NAME_CHARS || (i-j)<MIN_NAME_CHARS)return 0;
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;

	while(s[i] == ' ')i++;
	j = i;
	while(s[i]<=MAX_NAME_CHAR && s[i]>=MIN_NAME_CHAR)i++;
	if((i-j)>MAX_NAME_CHARS || (i-j)<MIN_NAME_CHARS)return 0;
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;
	
	while(s[i] == ' ')i++;
	if(s[i]== 'F'||s[i]== 'M'||s[i]== 'N')i++;
	else return 0;
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;
	

	while(s[i] == ' ')i++;
	d = atoi (&s[i]);
	//printf("d = %i \n",d);
	if (d>MAX_DAY || d<MIN_DAY)return 0;
	while(s[i]<='9' && s[i]>='0')i++; 
	//printf("i = %i \n",i);
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;

	
	
	while(s[i] == ' ')i++;
	m = atoi(&s[i]);
	if (m>MAX_MONTH || m<MIN_MONTH)return 0;
	while(s[i]<='9' && s[i]>='0')i++; 
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;
	
	
	
	
	while(s[i] == ' ')i++;
	y = atoi(&s[i]);
	if (y>MAX_YEAR || y<MIN_YEAR)return 0;
	while(s[i]<='9' && s[i]>='0')i++; 
	while(s[i] == ' ')i++;
	if(s[i]!= ',')return 0;
	i++;
	
	
	
	while(s[i] == ' ')i++;
	e = atoi (&s[i]);
	if (e>MAX_SALARY || e<MIN_SALARY)return 0;
	while(s[i]<='9' && s[i]>='0')i++; 
	while(s[i] == ' ')i++;
	
	if(s[i] != '\0') return 0;
	
	i = 0;
	
	j = 0;
	while(s[i] == ' ')i++;
	while(s[i]<=MAX_NAME_CHAR && s[i]>=MIN_NAME_CHAR){
		emps->lName[j] = s[i];
		i++;
		j++;
	}
	while(s[i] == ' ')i++;
	i++;
	
	j = 0;
	while(s[i] == ' ')i++;
	while(s[i]<=MAX_NAME_CHAR && s[i]>=MIN_NAME_CHAR){
		emps->mName[j] = s[i];
		i++;
		j++;
	}
	while(s[i] == ' ')i++;
	i++;
	
	j = 0;
	while(s[i] == ' ')i++;
	while(s[i]<=MAX_NAME_CHAR && s[i]>=MIN_NAME_CHAR){
		emps->fName[j] = s[i];
		i++;
		j++;
	}
	while(s[i] == ' ')i++;
	i++;
	
	
	while(s[i] == ' ')i++;
	emps->gender = s[i];
		
		
	
	
	
	emps->dob.day = d;
	emps->dob.month = m;
	emps->dob.year = y;
	emps->salary = e;
	
	return 1;
	
}

void getEmps(empType *emps, int n){
	char s[400];
	int i;
	
	i = 0;
	while (i < n){
		printf ("Please enter employee %i ...\n", i+1);
		gets(s);
		if(parseEmp(s,&emps[i])) i++;	// we got a valid employee!
		else{
			printf("invalid\n");
		}
	}
}


void sortEmpsByDOB (empType *emps, int n){
	
	empType temp;
	
	//for(int z = 0;z<n;z++){
	
	
		for(int i = 0; i<n;i++){
			if(emps[i].dob.year<emps[i+1].dob.year){
				temp = emps[i];
				emps[i] = emps[i+1];
				emps[i+1] = temp;
			}
		
		}
	//}
}

void outputEmps(empType *emps, int n){
	
	for(int i = 0;i<n;i++){
		printf("Last name = %s ",emps[i].lName);
		printf("Middle name = %s ",emps[i].mName);
		printf("First name = %s ",emps[i].fName);
		printf("Gender = %c ",emps[i].gender);
		printf("Day = %i ",emps[i].dob.day);
		printf("Month = %i ",emps[i].dob.month);
		printf("Year = %i ",emps[i].dob.year);
		printf("Salary = %i \n",emps[i].salary);
	}
}


int main(){
	empType emps[100];
	int numEmps = 2;
	
	
	
	getEmps(emps, numEmps);
	outputEmps (emps, numEmps);
	sortEmpsByDOB (emps, numEmps);
	outputEmps(emps, numEmps);
	
	
	return 0;
}
