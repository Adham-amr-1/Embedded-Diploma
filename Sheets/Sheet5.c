#include <stdio.h>
#include <stdlib.h>
/*void sum(int *x,int *y,int*summ){
    *summ= *x+*y;
}*/
/*
void max(int *x,int *y,int*maxi){
    *maxi = (*x >*y)? *x : *y;
}*/
/*
void storeinArray(int*arr,int sz){
    for(int i = 0; i < sz; i++){
        scanf("%i",&arr[i]);
    }
}
void printArray(int *arr,int sz){
    for(int i = 0; i < sz; i++){
        printf("%i\n",arr[i]);
    }
}*/
/*
void storeinArray(int*arr,int sz){
    for(int i = 0; i < sz; i++){
        scanf("%i",&arr[i]);
    }
}
void SumofArray(int*arr,int sz){
    int sum = 0;
    for(int i = 0; i < sz; i++){
        sum+=arr[i];
    }
    printf("Summ of Array = %i",sum);
}*/
/*int foo(int* p){
    printf("%i",*p);
}*/
int main()
{
    // Pointers & arrays
    /*
    int x, y,summ = 0;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    sum(&x,&y,&summ);
    printf("Sum = %i",summ);
    */
    /*
    int x, y,maxi = 0;
    printf("Enter 2 Numbers : ");
    scanf("%i%i",&x,&y);
    max(&x,&y,&maxi);
    printf("Max Number = %i",maxi);
    */
    /*
    int arr[5];
    int *ptr = arr;
    storeinArray(ptr,5);
    printf("\n\n");
    printArray(ptr,5);
    */
    /*
    int arr[5];
    int *ptr = arr;
    storeinArray(ptr,5);
    printf("\n\n");
    SumofArray(ptr,5);
    */
    /*int i = 10, *p = &i;
    foo(&i);*/
    /*
    int arr[10] ={};
    int *p = arr;
    printf("%p\n",p);
    p++;
    printf("%p\n",p);*/
    /*
    int i = 0x12345678;
    char *p =&i;
    printf("%x\n",*p);
    */
    /*
    int arr[5] = {5,4,3,2,1};
    int arr2[5];
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++){
        arr2[i] = arr[i];
    }
    for(int i = 0; i < size; i++){
        printf("%i\n",arr2[i]);
    }
    */
    /*
    int arr[5] = {5,8,10,1,13}, max = 0, min = 10000;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(min>arr[i]){
            min = arr[i];
        }
    }
    printf("Maximum of array = %i\n",max);
    printf("Minimum of array = %i\n",min);*/
    /*
    int arr[10] , temp = 0;
    for(int i = 0; i < 10; i++){
        scanf("%i",&arr[i]);
    }
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 10; j++){
            if(arr[j]>arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%i\n",arr[i]);
    }*/
    /*
    int a;
    int* p;
    a = 2;
    p = &a;
    a = a + 1;
    printf("%d", *p);
    */
    /*
    int a;
    int b;
    int* p;
    int* q;
    a = 3;
    p = &a;
    q = p;
    b = 4;
    *q = b;
    printf("%d %d", *p,a);
    */
    return 0;
}
