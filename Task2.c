#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y ,z, max = 0;
    printf("Enter 3 Numbers : ");
    scanf("%i%i%i",&x,&y,&z);
    /*
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
    printf("Maximum is %i",max);
    */
    switch(((x>y)&&(x>z))+2*((x<y)&&(y>z))+3*((z>y)&&(x<z))){
    case 1 :
        printf("Maximum is %i",x);
        break;
    case 2 :
        printf("Maximum is %i",y);
        break;
    case 3 :
        printf("Maximum is %i",z);
        break;
    }

    return 0;
}
