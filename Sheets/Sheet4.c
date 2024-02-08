#include <stdio.h>
#include <stdlib.h>
/*int cube(int x){
    return x*x*x;
}*/
/*
void maxmin(int x, int y){
    return (x>y)? printf("Max = %i\nMin = %i",x,y):printf("Max = %i\nMin = %i",y,x);
}*/
/*void dectobin(int x){
    for(int i = 31; i>=0;i--){
        printf("%i",(x&(1u<<i))>>i);
    }
}*/
/*
int prime(int x){
    int flag = 0;
    if(x == 0 || x == 1){
        return flag;
    }
    else{
        for(int i = 2; i<(x/2);i++){
            if(x%i==0){
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
*/

int facto(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * facto(n-1);
}
/*void permarea(int l,int w){
    printf("Area = %i\nPerimeter = %i",l*w,2*(l+w));
}*/
int factsum(int n){
    int sum = 0;
    for(int i=n ; i > 0 ; i--){
        sum+= (facto(i)/i);
    }
    return sum;
}
int main()
{
    /*
    int n;
    printf("Enter Number : ");
    scanf("%i",&n);
    printf("Cube of %i = %i",n,cube(n));
    */
    /*
    int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    maxmin(x,y);
    */
    /*
    int n;
    printf("Enter Number : ");
    scanf("%i",&n);
    dectobin(n);
    */
    /*
    int n;
    printf("Enter Number : ");
    scanf("%i",&n);
    if(prime(n)){
        printf("Not Prime");
    }
    else{
        printf("Prime");
    }
    */
    /*
    int n;
    printf("Enter Number : ");
    scanf("%i",&n);
    printf("Factorial of %i = %i",n,facto(n));
    */
    /*
    int x,y;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    permarea(x,y);
    */
    
    int n;
    printf("Enter Number : ");
    scanf("%i",&n);
    printf("sum of series = %i", factsum(n));
    return 0;

}
