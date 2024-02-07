#include <stdio.h>
#include <stdlib.h>
/*int f(int x, int *py, int **ppz){
    int y,z;
    **ppz+=1;
    z=**ppz;
    *py+=2;
    y=*py;
    x+=3;
    return x + y + z ;

}*/
int main()
{

    // check if it's big endian or little endian
    int x = 1;
    char *ptr = &x;
    if(*ptr==1){
        printf("Little Endian");
    }
    else{
        printf("Big Endian");
    }
    /*
    int c, *b, **a;
    c = 4, b = &c, a= &b;
    printf("%i",f(c,b,a));
    */
    return 0;
}
