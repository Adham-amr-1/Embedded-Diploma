#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 20,y = 10 , temp;
    /* Way 1
    x = x + y;
    y = x - y;
    x = x - y;
    */
    /* Way 2
    temp = x;
    x = y;
    y = temp;
    */
    // Way 3
    x = x^y;
    y = x^y;
    x = x^y;
    printf("X = %i \nY = %i",x,y);

    return 0;
}
