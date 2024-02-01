#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Size Of The Data Types
    printf("Char = %i\n", sizeof(char));
    printf("Int = %i\n", sizeof(int));
    printf("Float = %i\n", sizeof(float));
    printf("Double = %i\n", sizeof(double));
    printf("Long Double = %i\n", sizeof(long double));
    */
    
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
    // The quotient and the remainder of two integers.
    signed int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    printf("There Reminder = %i\n", x % y);
    printf("There Quotient = %f", (float)x / y);
    
    
    return 0;
}
