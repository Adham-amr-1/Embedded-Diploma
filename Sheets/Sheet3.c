#include <stdio.h>
#include <stdlib.h>
int main()
{
    /*int n,sum = 0;
    printf("Enter Number : ");
    scanf("%i",&n);
    while(n){
        sum+=n;
        n--;
    }
    printf("Sum = %i",sum);*/
    /*int n,m;
    printf("Enter Number : ");
    scanf("%i",&n);
    m=n;
    while(n--){
        printf("welcome to embedded system\n");
    }
    printf("\n");
    for(int i = 0; i < m; i++){
        printf("welcome to embedded system\n");
    }*/
    /*
    int n, m = 0;
    printf("Enter Number : ");
    scanf("%i",&n);
    while(n){
        if(m%2==1){
            printf("%i\t",m);
            n--;
        }
        m++;
    }*/
    /*
    int n,sum = 0;
    label:
    printf("Enter Number : ");
    scanf("%i",&n);
    while(n>0){
        sum+=n;
        goto label;
    }
    printf("Sum = %i",sum);
    */
    /*
    int n,sum = 0,i;
    printf("Enter Number : ");
    scanf("%i",&i);
    while(i){
        printf("Enter Number : ");
        scanf("%i",&n);
        if(n>0){
            sum+=n;
            i--;
        }
        else{
            printf("Enter postive number \n");
        }
    }
    printf("Sum = %i",sum);
    */
    /*
    int n,facto = 1;
    printf("Enter Number : ");
    scanf("%i",&n);
    for(int i = n; i>0 ; i--){
        facto*=i;
    }
    printf("Factorial of %i = %i",n,facto);
    */
    /*
    int n,facto;
    printf("Enter Number : ");
    scanf("%i",&n);
    facto = n;
    for(int i = 3; i>1 ; i--){
        facto*=n;
    }
    printf("Cube of %i = %i",n,facto);
    */
    /*
    for(int i = 0;i<3;i++){
        for(int j = 0; j<5 ; j++){
            printf(" * ");
        }
        printf("\n");
    }*/
    /*
    for(int i = 0;i<4;i++){
        for(int j = 0; j<5 ; j++){
            if(i==1){
             printf(" *           * ");
             break;
            }
            else if(i==2){
             printf(" *           * ");
             break;
            }
            else{
                printf(" * ");
            }
        }
        printf("\n");
    }
    */
    /*
    int n,sum = 0;
    printf("Enter Number : ");
    scanf("%i",&n);
    for(int i = 1; i<=n; i++){
        printf("%i ",i*i);
        sum+= (i*i);
    }
    printf("\nSum = %i",sum);
    */
    /*
    long int n ,t = 9;
    long long sum = 0;
    printf("Enter Number : ");
    scanf("%i",&n);
    for(int i = 0; i < n ;i++){
        printf("%ld ",t);
        sum+=t;
        t = t * 10 + 9;
    }
    printf("\nSum = %lld",sum);
    */
    /*
    for(int i = 1; i <= 6;i++){
        for(int j = 0 ; j < i;j++){
            printf(" * ");
        }
        printf("\n");
    }*/
    /*
    for(int i = 1; i <= 6;i++){
        for(int j = 6 ; j >= i;j--){
            printf(" * ");
        }
        printf("\n");
    }*/
    /*
    for(int i = 1; i <= 6;i++){
        for(int j = 6 ; j >= i;j--){
           if(i == 2){
            printf(" *           * ");
            break;
           }
            else if(i == 3){
            printf(" *        * ");
            break;
           }
            else if(i == 4){
            printf(" *     * ");
            break;
           }
           else{
             printf(" * ");
           }
        }
        printf("\n");
    }*/
    /*
    for(int i = 1; i <= 6;i++){
        for(int j = 6 ; j >= i;j--){
           if(i == 6){
            printf("\t     *");
            break;
           }
            else if(i == 5){
            printf("\t    * * ");
            break;
           }
            else if(i == 4){
            printf("\t   * * * ");
            break;
           }
            else if(i == 3){
            printf("\t  * * * *  ");
            break;
           }
            else if(i == 2){
            printf("\t * * * * *  ");
            break;
           }
            else if(i == 1){
            printf("\t* * * * * * ");
            break;
           }
        }
        printf("\n");
    }*/
    /*
        for(int i = 1; i <= 6;i++){
        for(int j = 6 ; j >= i;j--){
           if(i == 1){
            printf("\t     *");
            break;
           }
            else if(i == 2){
            printf("\t    * * ");
            break;
           }
            else if(i == 3){
            printf("\t   * * * ");
            break;
           }
            else if(i == 4){
            printf("\t  * * * *  ");
            break;
           }
            else if(i == 5){
            printf("\t * * * * *  ");
            break;
           }
            else if(i == 6){
            printf("\t* * * * * * ");
            break;
           }
        }
        printf("\n");
    }*/
            for(int i = 1; i <= 6;i++){
        for(int j = 6 ; j >= i;j--){
           if(i == 1){
            printf("\t     *");
            break;
           }
            else if(i == 2){
            printf("\t    * * ");
            break;
           }
            else if(i == 3){
            printf("\t   *   * ");
            break;
           }
            else if(i == 4){
            printf("\t  *     *  ");
            break;
           }
            else if(i == 5){
            printf("\t *       *  ");
            break;
           }
            else if(i == 6){
            printf("\t* * * * * * ");
            break;
           }
        }
        printf("\n");
    }
    return 0;
}
