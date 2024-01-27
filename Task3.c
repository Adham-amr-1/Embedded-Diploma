#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, flag = 0;
    printf("Enter a Number : ");
    scanf("%i",&x);
    if(x%2==0){
        printf("The Number Is Even\n");
    }
    else{
        printf("The Number Is odd\n");
    }
    for(int i=2;i<=(x/2);i++){
        if(x%i == 0){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("The Number is not prime\n");
    }
    else{
        printf("The Number is prime\n");
    }
    return 0;
}
