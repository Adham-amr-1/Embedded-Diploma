#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Part 1 Basics
    /* Add Two Numbers
    signed int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    printf("There Sum = %i", x + y);
    */
    /* Multiplying two floating number
    float x,y;
    printf("Enter 2 Numbers : ");
    scanf("%f%f",&x,&y);
    printf("There Multiplication = %f", x * y);
    */
    /* The quotient and the remainder of two integers.
    signed int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    printf("There Reminder = %i\n", x % y);
    printf("There Quotient = %f", (float)x / y);
    */
    // Part 2 Conditions
    /* Check whether even or odd
    signed int x;
    printf("Enter a number : ");
    scanf("%i",&x);
    if(x%2==0){
        printf("The Number Is Even");
    }
    else{
        printf("The Number Is Odd");
    }
    */
    /* Find The Maximum
    signed int x, y, z, max = 0;
    printf("Enter 3 Numbers : ");
    scanf("%i%i%i",&x,&y,&z);
    if(x>y){
        if(x>z){
            max = x;
        }
        else{
            max = z;
        }
    }
    else{
        if(y>z){
            max = y;
        }
        else{
            max = z;
        }
    }
     printf("The Maximum Number Is %i",max);
    */
    /* check whether a triangle is Equilateral, Isosceles or Scalene.
    signed int x,y,z;
    printf("Enter 3 Numbers : ");
    scanf("%i%i%i",&x,&y,&z);
    if((x==y)&&(x==z)&&(y==z)){
        printf("This Is An Equilateral triangle ");
    }
    else if((x==y)||(x==z)||(y==z)){
        printf("This Is An Isoceles triangle ");
    }
    else{
        printf("This Is An Scalene triangle ");
    }
    */
    /* Calc. Using Switch
    float x,y;
    char op;
    printf("Enter 2 Numbers : ");
    scanf("%f%f",&x,&y);
    fflush(stdin);
    printf("Enter op : ");
    scanf("%c",&op);
    switch(op){
    case '+':
        printf("%f + %f = %f", x, y, x + y);
        break;
    case '-':
        printf("%f - %f = %f", x, y, x - y);
        break;
    case '*':
        printf("%f x %f = %f", x, y, x * y);
        break;
    case '/':
        if(y!=0){
            printf("%f / %f = %f", x, y, x / y);
        }
        else{
            printf("Cannot Divide by Zero");
        }
        break;
    default:
        printf("Invalid Operation");
    }
    */
    // Enter Number To Know which day respond for this Number
    signed int x;
    label1:
    printf("Enter a number ( 1 ~ 7 ) : ");
    scanf("%i",&x);
    switch(x){
    case 1:
        printf("Saturday");
        break;
    case 2:
        printf("Sunday");
        break;
    case 3:
        printf("Monday");
        break;
    case 4:
        printf("Tuesday");
        break;
    case 5:
        printf("Wednesday");
        break;
    case 6:
        printf("Thursday");
        break;
    case 7:
        printf("Friday");
        break;
    default:
        printf("\n         **WARNING**\n The Number Must Be From ( 1 ~ 7 )\n\n");
        goto label1;
    }
    return 0;
}
