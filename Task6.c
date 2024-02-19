#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
    /*
    int arr[5],max,min;
    print("Enter Array Elements : ");
    for(int i = 0; i < 5; i++){
        scanf("%i",arr+i);
    }
    max = min = arr[0];
    for(int i = 1; i < 5; i++){
        if(min > arr[i]){
            min = arr[i];
        }
        if(max < arr[i]){
            max=arr[i];
        }
    }
    printf("Max = %i\nMin = %i",max,min);
    */
    /*
    int x,y,arr[10];
    printf("Enter Number : ");
    scanf("%i",&x);

    while(x>0){
        y%=x;
        if(arr[y]==1){
            break;
        }
            x/=10;
            arr[y]=1;
    }
    if(x==0){
        printf("There's No Repeated Number");
    }
    else{
        printf("There's Repeated Number");
    }*/
    /*
    int arr[] = {1,2,3,3,2,5,7,1,5};
    int y = arr[0];
    for(int i = 1; i<(sizeof(arr)/sizeof(int));i++){
        y^=arr[i];
    }
    printf("The Unrepeated element in array is %i",y);
    */
    int arr[5];
    printf("Enter Array Elements : ");
    for(int i = 0; i < 5; i++){
        scanf("%i",arr+i);
    }
    printf("Before Sorting : \n");
    for(int i = 0; i < 5; i++){
        printf("%i ",arr[i]);
    }
    printf("\n\n");
    for(int i = 0; i<4;i++){
            int minindex = i;
        for(int j = i + 1; j < 5; j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
    }
    printf("After Sorting : \n");
    for(int i = 0; i < 5; i++){
        printf("%i ",arr[i]);
    }
    return 0;
}
