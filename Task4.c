#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, ones = 0,i;
    printf("Enter a Number : ");
    scanf("%i",&x);
    for(i=0;i<32;i++){
        if(((x&(1u<<i))>>i) == 1){
            ones++;
        }
    }
    printf("Number Of Ones = %i",ones);
    return 0;
}
