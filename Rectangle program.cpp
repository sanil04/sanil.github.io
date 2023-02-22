#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 1024

#define MPW_LT 0
#define MPW_RT 800
#define MPW_BOT 0
#define MPW_TOP 600

#define RECT_NAME_CHARS 5
#define RECT_MIN_NAME_CHAR 'a'
#define RECT_MAX_NAME_CHAR 'd'

#define MAX_RECTS 200
#define MAX_U_I 500

#define GET_USER_RECT 1
#define GET_RAND_RECT 2
#define FIND_RECT 3
#define DEL_RECT 4
#define COMPUTE_RECT 5
#define OUTPUT_RECTS 6
#define OUTPUT_CALCULATED_RECTS 7
#define QUIT 8

typedef struct{
	int lt, rt, bot, top;
	char name[RECT_NAME_CHARS + 1];
	int area, perimeter;
}rectType;

typedef struct{
	rectType r1, r2;
	rectType unionRect;
	rectType sectRect;
	int intersection;	// 0 means no intersection, 1 means intersection
}rectMathType;

int fgetInt(){
    int value = 0;
    char input[MAX_CHARS];
    fgets(input, MAX_CHARS, stdin);
    sscanf(input, "%d", &value);
    return value;
}

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int min(int a, int b){
    if (a < b) return a;
    else return b;
}

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

void crStr(char *str, int minLen, int maxLen, char minChar, char maxChar){
	int i = getRand(minLen, maxLen);
	for (int j = 0; j < i; j++) str[j] = getRand(minChar, maxChar);
	str[i] = 0;
}

int checkName(char *str, const rectType *myRects, int n){
    if(strlen(str) != RECT_NAME_CHARS) return 1;
    for (int i = 0; str[i]; i++){
        if(str[i] < RECT_MIN_NAME_CHAR || str[i] > RECT_MAX_NAME_CHAR) return 1;
    }
    for (int i = 0; i < n; i++){
        if (!strcmp(str, myRects[i].name)) return 1;
    }
    return 0;
}

void insertRect(rectType rect, rectType *myRects, int n){
    int i;
    for(i = n-1; i >= 0; i--){
        if (strcmp(myRects[i].name, rect.name) < 0) break;
        myRects[i+1] = myRects[i];
    }
    myRects[i+1] = rect;
}

void getUserRectangle(rectType *myRects, int numRects){
    rectType rT;
    int check = 1;

    while(check){
        printf("Please enter left: ");
        rT.lt = fgetInt();
        if((rT.lt)>(MPW_RT-1) ||(rT.lt)<(MPW_LT)){
          printf("please enter valid input\n");
          check = 1;
        }
        else check = 0;
    }
    check = 1;
    while(check){

        printf("Please enter right: ");
        rT.rt = fgetInt();
        if((rT.rt)>(MPW_RT) ||(rT.rt)<=(rT.lt)){
          printf("please enter valid input\n");
          check = 1;
        }
        else check = 0;
    }
    check = 1;
    while(check){

        printf("Please enter bot: ");
        rT.bot = fgetInt();
        if((rT.bot)<(MPW_BOT) ||(rT.bot)>(MPW_TOP-1)){
          printf("please enter valid input\n");
          check = 1;
        }
        else check = 0;
    }
    check = 1;
    while(check){
        printf("Please enter top: ");
        rT.top = fgetInt();
        if((rT.top)>(MPW_TOP) ||(rT.top)<=(rT.bot)){
          printf("please enter valid input\n");
          check = 1;
        }
        else check = 0;
    }
    check = 1;
    while(check){
        printf("Please enter name: ");
        char input[MAX_CHARS];
        fgets(input, MAX_CHARS, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if(checkName(input, myRects, numRects)){
          printf("Please enter valid input\n");
          check = 1;
        }
        else {
            check = 0;
            strcpy(rT.name, input);
        }
    }

    rT.area = (rT.top - rT.bot)*(rT.rt - rT.lt);
    rT.perimeter = ((rT.top - rT.bot)+(rT.rt - rT.lt))*2;

    insertRect(rT, myRects, numRects);
    printf("Rectangle %s added.\n", rT.name);
}

void getRandomRect(rectType *rects, int numRects){
    rectType rect;
    rect.lt = getRand(MPW_LT, MPW_RT-1);
    rect.rt = getRand(rect.lt+1, MPW_RT);
    rect.bot = getRand(MPW_BOT, MPW_TOP-1);
    rect.top = getRand(rect.bot+1, MPW_TOP);
    rect.area = (rect.top - rect.bot) * (rect.rt - rect.lt);
    rect.perimeter = 2 * (rect.top - rect.bot) +  2 * (rect.rt - rect.lt);

    do{
        crStr(rect.name, RECT_NAME_CHARS, RECT_NAME_CHARS, RECT_MIN_NAME_CHAR, RECT_MAX_NAME_CHAR);
    }while (checkName(rect.name, rects, numRects));

    insertRect(rect, rects, numRects);
    printf("Rectangle %s added.\n", rect.name);
}

void outputRectangle(FILE *fp, rectType rect){
    fprintf(fp, "%s: Left-Bottom (%i, %i), Right-Top (%i, %i); A = %i, P = %i\n", rect.name, rect.lt, rect.bot, rect.rt, rect.top, rect.area, rect.perimeter);
}

void findRectangle(const rectType *myRects, int n){
    printf("Enter the rectangle name to find:\n");
    char input[MAX_CHARS];
    fgets(input, MAX_CHARS, stdin);
    input[strcspn(input, "\n")] = 0;
    for (int i = 0; i < n; i++){
        if(!strcmp(input, myRects[i].name)){
            outputRectangle(stdout, myRects[i]);
            return;
        } 
    }
    printf("Rectangle %s was not found.\n", input);
}

int deleteRectangle(rectType *myRects, int n){
    printf("Enter the rectangle name to delete:\n");
    char input[MAX_CHARS];
    fgets(input, MAX_CHARS, stdin);
    input[strcspn(input, "\n")] = 0;
    for (int i = 0; i < n; i++){
        if(!strcmp(input, myRects[i].name)){
            while (i < n-1){
                myRects[i] = myRects[i+1];
                i++;
            }
            printf("Deleted rectangle %s.\n", input);
            return 1;
        }
    }
    printf("Rectangle %s was not found.\n", input);
    return 0;
}

void outputStats(FILE *fp, rectMathType rectMath){
    char temp[40];
    int spacing = -24;

    sprintf(temp, "%s union %s", rectMath.r1.name,rectMath.r2.name);
    fprintf(fp, "%s, (%i, %i), (%i, %i), %i, %i\n", rectMath.r1.name, rectMath.r1.lt, rectMath.r1.bot, rectMath.r1.rt, rectMath.r1.top, rectMath.r1.perimeter, rectMath.r1.area);
    fprintf(fp, "%s, (%i, %i), (%i, %i), %i, %i\n",rectMath.r2.name, rectMath.r2.lt, rectMath.r2.bot, rectMath.r2.rt, rectMath.r2.top, rectMath.r2.perimeter, rectMath.r2.area);
    fprintf(fp, "%*s = (%i, %i), (%i, %i)\n", spacing, temp, rectMath.unionRect.lt,rectMath.unionRect.bot,rectMath.unionRect.rt,rectMath.unionRect.top);

    if(rectMath.intersection == 1){
        sprintf(temp, "%s intersection %s", rectMath.r1.name, rectMath.r2.name);
        fprintf(fp, "%*s = (%i, %i), (%i, %i)\n", spacing, temp, rectMath.sectRect.lt, rectMath.sectRect.bot, rectMath.sectRect.rt, rectMath.sectRect.top);
    }
    else{
        fprintf(fp, "No intersection\n");
    }
}

int checkDuplicateUnionIntersection(const rectMathType *rectsMath, rectMathType rectMath, int n){
    for (int i = 0; i < n; i++){
        if(!strcmp(rectMath.r1.name, rectsMath[i].r1.name) && !strcmp(rectMath.r2.name, rectsMath[i].r2.name)) return 1;
    }
    return 0;
}

void insertRectMath(rectMathType *rectsMath, rectMathType rectMath, int n){
    int i, a;
    for(i = n-1; i >= 0; i--){
        a = strcmp(rectsMath[i].r1.name, rectMath.r1.name);
        if (a < 0) break;
        else if (a == 0 && strcmp(rectsMath[i].r2.name, rectMath.r2.name) < 0) break;
        rectsMath[i+1] = rectsMath[i];
    }
    rectsMath[i+1] = rectMath;
}

void computeUnionIntersection(rectMathType *rectsMath, rectType *myRects, int numUnionIntersections, int numRects){
    int spacing = -24;
    rectMathType rectMath;
    do{
        int a = getRand(0, numRects-1);
        int b = getRand(0, numRects-1);
        rectMath.r1 = myRects[min(a, b)];
        rectMath.r2 = myRects[max(a, b)];
    }while(checkDuplicateUnionIntersection(rectsMath, rectMath, numUnionIntersections));

    rectMath.unionRect.lt = min(rectMath.r1.lt, rectMath.r2.lt);
    rectMath.unionRect.rt = max(rectMath.r1.rt, rectMath.r2.rt);
    rectMath.unionRect.bot = min(rectMath.r1.bot, rectMath.r2.bot);
    rectMath.unionRect.top = max(rectMath.r1.top, rectMath.r2.top);

    rectMath.unionRect.perimeter = 2*((rectMath.unionRect.rt-rectMath.unionRect.lt)+(rectMath.unionRect.top-rectMath.unionRect.bot));

    if (min(rectMath.r1.rt, rectMath.r2.rt) <= max(rectMath.r1.lt, rectMath.r2.lt) || min(rectMath.r1.top, rectMath.r2.top) <= max(rectMath.r1.bot, rectMath.r2.bot)) rectMath.intersection = 0;
    else rectMath.intersection = 1;
    
    if(rectMath.intersection == 1){

        rectMath.sectRect.lt = max(rectMath.r1.lt, rectMath.r2.lt);
        rectMath.sectRect.rt = min(rectMath.r1.rt, rectMath.r2.rt);
        rectMath.sectRect.bot = max(rectMath.r1.bot, rectMath.r2.bot);
        rectMath.sectRect.top = min(rectMath.r1.top, rectMath.r2.top);
    }
    outputStats(stdout, rectMath);
    insertRectMath(rectsMath, rectMath, numUnionIntersections);
}


void outputRectangles(const rectType *myRects, int n){
    printf("Here are your rectangles...\n\n");
    for (int i = 0; i < n; i++) outputRectangle(stdout, myRects[i]);
    printf("\n");
}

void outputUnionIntersections(rectMathType *rectsMath, int n){
    printf("Here are your union/intersection statistics...\n\n");
    for (int i = 0; i < n; i++){
        outputStats(stdout, rectsMath[i]);
        printf("\n");
    }
}

void writeToFile(rectType *myRects, int numRects, rectMathType *rectsMath, int numUnionIntersections){
    char filename[50] = "myRectangles.txt";
    printf("Writing to output file %s...\n", filename);
    
    FILE *fp = fopen(filename, "w");

    if(fp == NULL){
        printf("Error opening file.");
        exit(-1);
    }

    if (numRects <= 0) fprintf(fp, "No rectangles to display.\n\n");
    else{
        fprintf(fp, "Here are your rectangles...\n\n");
        for(int i = 0; i < numRects; i++) outputRectangle(fp, myRects[i]);
        fprintf(fp, "\n");
    }

    if(numUnionIntersections == 0) fprintf(fp, "No Union/Intersections to display.\n\n");
    else{
        fprintf(fp, "Here are your union/intersection statistics...\n\n");
        for(int i = 0; i < numUnionIntersections; i++){
            outputStats(fp, rectsMath[i]);
            fprintf(fp, "\n");
        }
    }

    fclose(fp);            
    printf("Exiting program...\n\n");
}

void display_options(){
    printf("Here are your options:\n");
    printf("1.\tInsert User Rectangle.\n");
    printf("2.\tInsert Random Rectangle.\n");
    printf("3.\tFind Rectangle.\n");
    printf("4.\tDelete Rectangle.\n");
    printf("5.\tCompute and Insert Union/Intersection Statistics.\n");
    printf("6.\tOutput Rectangles.\n");
    printf("7.\tOutput Union/Intersections Statistics.\n");
    printf("8.\tQuit.\n");
}

int main() {
	rectType myRects[MAX_RECTS];
	rectMathType rectsMath[MAX_U_I];
	int numRects = 0;    // initially there are no rectangles
	int numUnionIntersections = 0;    // initially no union/intersections computed
    srand(time(NULL));
    while(1){
        printf("================================================\n");
        printf("Welcome to the rectangle program!\nHere are the menu options:\n");
        printf("================================================\n");
        display_options();
        printf("================================================\n");
        printf("Please enter a menu option:\n");
        printf("================================================\n");
        switch (fgetInt()) {
            case GET_USER_RECT:
                printf("\n");
                if(numRects < MAX_RECTS){
                    getUserRectangle(myRects, numRects);
                    numRects++;
                }
                break;
            case GET_RAND_RECT:
                printf("\n");
                if (numRects < MAX_RECTS){
                  getRandomRect(myRects, numRects);
                  numRects++;
                }
                break;
            case FIND_RECT:
                printf("\n");
                findRectangle(myRects, numRects);
                break;
            case DEL_RECT:
                printf("\n");
                if (numRects <= 0) printf("Error: No rectangles to delete.\n");
                else numRects -= deleteRectangle(myRects, numRects);
                break;
            case COMPUTE_RECT:
                printf("\n");
                if (numUnionIntersections < MAX_U_I && numRects >= 2 && numUnionIntersections < (int) ((((float)numRects+1)*((float) numRects/2)))){
                    computeUnionIntersection(rectsMath, myRects, numUnionIntersections, numRects);
                    numUnionIntersections++;
                }
                else{
                    printf("Error: could not compute rectangles.\n");
                }
                break;
            case OUTPUT_RECTS:
                printf("\n");
                if (numRects <= 0) printf("Error: No rectangles to display.\n");
                else outputRectangles(myRects, numRects);
                break;
            case OUTPUT_CALCULATED_RECTS:
                printf("\n");
                if(numUnionIntersections == 0) printf("Error: No Union/Intersections to display.\n");
                else{
                    outputUnionIntersections(rectsMath, numUnionIntersections);
                }
                break;
            case QUIT:
                printf("\n");
                writeToFile(myRects, numRects, rectsMath, numUnionIntersections);
                return 0;
                break;
            default:
                printf("\n");
                printf("Invalid menu option, please try again.\n");
        }
        printf("\n");
        printf("Press any key to continue...");
        getchar();
        printf("\e[1;1H\e[2J");
    }
}

