#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Print If it's -ve Number
    signed int x;
    printf("Enter Number : ");
    scanf("%i",&x);
    if((x&(1u<<((8*sizeof(x)-1)))>>((8*sizeof(x)-1))== 1)){
        printf("X = %i",x);
    }
    */
    /* Compare between 2 numbers
    signed int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    if(x>y){
        printf("%i Is the Largest",x);
    }
    else if("y>x"){
        printf("%i Is the Largest",y);
    }
    else{
        printf("The two Numbers are Equal");
    }
    */
    /* Check if ir's Alpha or not
    char x;
    printf("Enter a Char : ");
    scanf("%c",&x);
    switch(x){
    case 'a' ... 'z':
    case 'A' ... 'Z':
        printf("It's Alphabetic");
        break;
    default:
        printf("It's Not Alphabetic");
    }
    */
    /* voting age
    signed int x;
    printf("Enter Your Age : ");
    scanf("%i",&x);
    if(x<18){
          printf("You are not eligible for casting your vote");
    }
    else{
        printf("Congratulation! You are eligible for casting your vote");
    }
    */
    /* Compare Using Switch
    signed int x,y,max = 0;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    switch(x>y){
    case 1:
        max = x;
        break;
    case 0:
        max = y;
        break;
    }
    printf("Maximum = %i",max);
    */
    signed int x;
    printf("Enter Number : ");
    scanf("%i",&x);
    switch(x>0){
    case 1:
        printf("Positive Value");
        break;
    case 0:
        printf("Negative Value");
        break;
    }

    return 0;
}
