#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_CHARS 1024

#define MAX_FRACTIONS 100
#define MAX_EQUATIONS 100
#define MIN_NUMERATOR -99
#define MAX_NUMERATOR 99
#define MIN_DENOMINATOR -99
#define MAX_DENOMINATOR 99

#define RANDOM_FRACTION 1
#define GET_FRACTION 2
#define DISPLAY_FRACTIONS 3
#define ADD_FRACTIONS 4
#define SUBTRACT_FRACTIONS 5
#define DIVIDE_FRACTIONS 6
#define MULTIPLY_FRACTIONS 7
#define DISPLAY_EQUATIONS 8
#define EXIT 9

#define NUMERATOR 0
#define DENOMINATOR 1

int fgetInt(){
    int value = 0;
    char input[MAX_CHARS];
    fgets(input, MAX_CHARS, stdin);
    sscanf(input, "%d", &value);
    return value;
}

// random number between generator
int get_rand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int find_gcd(int a, int b){
    return b == 0 ? a : find_gcd(b, a % b);
}

void simplify_fraction(int *res_num, int *res_den, int num, int den){
    int gcd = find_gcd(num, den);
    *res_num = num / gcd;
    *res_den = den / gcd;
    if (*res_den < 0){
        *res_num *= -1;
        *res_den *= -1;
    }
}

int check(int a, int is_denom){
    if (is_denom){
        if (a > MAX_DENOMINATOR || a < MIN_DENOMINATOR || a == 0) return 1;
        else return 0;
    }
    else{
        if (a > MAX_NUMERATOR || a < MIN_NUMERATOR) return 1;
        else return 0;
    }
}

void create_random_fraction(int *numerator, int *denominator){
    *numerator = get_rand(MIN_NUMERATOR,MAX_NUMERATOR);
    do{
        *denominator = get_rand(MIN_NUMERATOR,MAX_NUMERATOR);
    } while (*denominator == 0);
    printf("Your random fraction is %i/%i\n", *numerator, *denominator);
}

void get_fraction(int *numerator, int *denominator){
    do{
        printf("Please enter the numerator (between %i and %i inclusive): ", MIN_NUMERATOR, MAX_NUMERATOR);
        *numerator = fgetInt();
        if (check(*numerator, NUMERATOR)) printf("Invalid numerator, please try again.\n");
    } while (check(*numerator, NUMERATOR));

     do{
        printf("Please enter the denominator (between %i and %i inclusive, cannot be 0): ", MIN_DENOMINATOR, MAX_DENOMINATOR);
        *denominator = fgetInt();
        if (check(*denominator, DENOMINATOR)) printf("Invalid denominator, please try again\n");
    } while (check(*denominator, DENOMINATOR));
    printf("Your inputted fraction is %i/%i\n", *numerator, *denominator);
}

void display_fractions(int fractions[MAX_FRACTIONS][2], int n){
    if (n == 0) {printf("There are no fractions to display.\n"); return;}
    int simp_frac[2];
    for(int i = 0; i < n; i++){
        printf("Fraction #%i: %i/%i = ", i+1 ,fractions[i][0], fractions[i][1]);
        simplify_fraction(&simp_frac[0], &simp_frac[1], fractions[i][0], fractions[i][1]);
        printf("%i/%i\n", simp_frac[0], simp_frac[1]);
    }
}

void add_fractions(char *str){
    int addend1[2];
    int addend2[2];

    printf("Enter the two fractions you'd like to add.\n");
    printf("\n");
    printf("Please enter fraction #1:\n");
    get_fraction(&addend1[0], &addend1[1]);
    printf("\n");
    printf("Please enter fraction #2:\n");
    get_fraction(&addend2[0], &addend2[1]);
    printf("\n");

    int resultn = addend1[0]*addend2[1] + addend2[0]*addend1[1];
    int resultd = addend1[1]*addend2[1];

    simplify_fraction(&resultn, &resultd, resultn, resultd);

    sprintf(str, "%i/%i + %i/%i = %i/%i", addend1[0], addend1[1], addend2[0], addend2[1], resultn, resultd);
    printf("Here is the result:\n%s\n", str);
}

void subtract_fractions(char *str){
    int minuend[2];
    int subtrahend[2];

    printf("Enter the two fractions you'd like to subtract.\n");
    printf("\n");
    printf("Please enter the minuend (first part):\n");
    get_fraction(&minuend[0], &minuend[1]);
    printf("\n");
    printf("Please enter fraction the subtrahend (second part):\n");
    get_fraction(&subtrahend[0], &subtrahend[1]);
    printf("\n");

    int resultn = minuend[0]*subtrahend[1] - subtrahend[0]*minuend[1];
    int resultd = minuend[1]*subtrahend[1];

    simplify_fraction(&resultn, &resultd, resultn, resultd);

    sprintf(str, "%i/%i - %i/%i = %i/%i", minuend[0], minuend[1], subtrahend[0], subtrahend[1], resultn, resultd);
    printf("Here is the result:\n%s\n", str);
}

void divide_fractions(char *str){
    int dividend[2];
    int divisor[2];
    int quotient[2];

    printf("Enter the two fractions you'd like to divide.\n");
    printf("\n");
    printf("Please enter the dividend (first part):\n");
    get_fraction(&dividend[0], &dividend[1]);
    printf("\n");
    do{
        printf("Please enter the divisor (second part):\n");
        get_fraction(&divisor[0], &divisor[1]);
        if (divisor[0] == 0) printf("ERROR: Invalid divisor, you cannot divide by zero.\n\n");
    }while(divisor[0] == 0);
    printf("\n");

    quotient[0] = dividend[0]*divisor[1];
    quotient[1] = dividend[1]*divisor[0];

    simplify_fraction(&quotient[0], &quotient[1], quotient[0], quotient[1]);

    sprintf(str, "%i/%i / %i/%i = %i/%i", dividend[0], dividend[1], divisor[0], divisor[1], quotient[0], quotient[1]);
    printf("Here is the result:\n%s\n", str);
}

void multiply_fractions(char *str){
    int fraction[2];
    int frac[2];
    int result[2];

    printf("Enter the two fractions you'd like to multiply.\n");
    printf("\n");
    printf("Please enter fraction #1:\n");
    get_fraction(&fraction[0], &fraction[1]);
    printf("\n");
    printf("Please enter fraction #2:\n");
    get_fraction(&frac[0], &frac[1]);
    printf("\n");

    result[0] = fraction[0]*frac[0];
    result[1] = fraction[1]*frac[1];

    simplify_fraction(&result[0], &result[1], result[0], result[1]);

    sprintf(str, "%i/%i * %i/%i = %i/%i", fraction[0], fraction[1], frac[0], frac[1], result[0], result[1]);
    printf("Here is the result:\n%s\n", str);
}

void display_equations(char equations[MAX_EQUATIONS][MAX_CHARS], int n){
    if (n == 0) {printf("There are no equations to display.\n"); return;}
    for(int i=0; i<n; i++){
        printf("Equation #%i: %s\n", i+1, equations[i]);
    }
}

void display_options(){
    printf("Here are your options:\n");
    printf("\t1. Generate random fraction.\n");
    printf("\t2. Get fraction from user.\n");
    printf("\t3. Display all generated fractions from 1 and 2.\n");
    printf("\t4. Add fractions.\n");
    printf("\t5. Subtract fractions.\n");
    printf("\t6. Divide fractions.\n");
    printf("\t7. Multiply fractions.\n");
    printf("\t8. Display all generated equations from 4, 5, 6, and 7.\n");
    printf("\t9. Exit.\n");
}

// main program
int main(){
    srand(time(NULL));
    int menu_option;
    int fractions[MAX_FRACTIONS][2]; // 0 = numberator, 1 = denominator
    char equations[MAX_EQUATIONS][MAX_CHARS];
    int n = 0;
    int num_eq = 0;
    while (1){
        printf("================================================\n");
        printf("Welcome to the fraction program!\n");
        printf("================================================\n");
        display_options();
        printf("================================================\n");
        printf("Please enter a menu option: ");
        menu_option = fgetInt();
        printf("================================================\n");
        switch (menu_option) {
            case RANDOM_FRACTION:
                if (n < MAX_FRACTIONS){
                    create_random_fraction(&fractions[n][0], &fractions[n][1]);
                    n++;
                }
                else printf("Too many fractions in array!\n");
                break;
            case GET_FRACTION:
                if (n < MAX_FRACTIONS){
                    get_fraction(&fractions[n][0], &fractions[n][1]);
                    n++;
                }
                else printf("Too many fractions in array!\n");
                break;
            case DISPLAY_FRACTIONS:
                display_fractions(fractions, n);
                break;
            case ADD_FRACTIONS:
                if (num_eq < MAX_EQUATIONS){
                    add_fractions(equations[num_eq]);
                    num_eq++;
                }
                else printf("Too many equations!\n");
                break;
            case SUBTRACT_FRACTIONS:
                if (num_eq < MAX_EQUATIONS){
                    subtract_fractions(equations[num_eq]);
                    num_eq++;
                }
                else printf("Too many equations!\n");
                break;
            case DIVIDE_FRACTIONS:
                if (num_eq < MAX_EQUATIONS){
                    divide_fractions(equations[num_eq]);
                    num_eq++;
                }
                else printf("Too many equations!\n");
                break;
            case MULTIPLY_FRACTIONS:
                if (num_eq < MAX_EQUATIONS){
                    multiply_fractions(equations[num_eq]);
                    num_eq++;
                }
                else printf("Too many equations!\n");
                break;
            case DISPLAY_EQUATIONS:
                display_equations(equations, num_eq);
                break;
            case EXIT:
                printf("Exiting program...\n\n");
                return 0;
            default:
                printf("Invalid menu option.\n");
        }
        printf("================================================\n");
        system("pause");
        system("cls");
    }
}
