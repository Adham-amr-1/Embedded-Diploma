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
   #include <stdio.h>
#include <stdlib.h>
int main()
{
    /*int arr[10];
    for(int i = 0; i<10;i++){
        scanf("%i",&arr[i]);
    }
    printf("\nBefore Reversing\n");
    for(int i = 0; i<10;i++){
        printf("%i ",arr[i]);
    }
    printf("\nAfter Reversing\n");
    for(int i = 9; i>=0;i--){
        printf("%i ",arr[i]);
    }
    */
    /*int arr[10],sum = 0;
    for(int i = 0; i<10;i++){
        scanf("%i",&arr[i]);
    }

    for(int i = 0; i<10;i++){
        sum+=arr[i];
    }
    printf("\nSum of array = %i",sum);
    */
    /*
    int arr1[10],arr2[10];
    for(int i = 0; i<10;i++){
        scanf("%i",&arr1[i]);
    }
    printf("\nArray 1 :\n");
    for(int i = 0; i<10;i++){
        printf("%i ",arr1[i]);
        arr2[i]=arr1[i];
    }
    printf("\nArray 2 :\n");
    for(int i = 0; i<10;i++){
        printf("%i ",arr2[i]);
    }*/
    /*int arr1[5] = {1,3,5,7,8}, arr2[5] = {2,4,9,10,6},arr3[10], max1 = 0, max2 = 0;
    for(int i = 0; i < 4;i++){
           int maxindex1 = i ,  maxindex2 = i;
        for(int j = i + 1 ; j < 5 ; j++){
        if(arr1[j]>arr1[maxindex2]){
            maxindex1 = j;
        }
        if(arr2[j]>arr2[maxindex2]){
            maxindex2 = j;
        }
        }
            int temp = arr1[maxindex1];
            arr1[maxindex1]   = arr1[i];
            arr1[i] = temp;
            temp = arr2[maxindex2];
            arr2[maxindex2]   = arr2[i];
            arr2[i] = temp;
    }
    printf("\nArray 1 :\n");
    for(int i = 0; i<5;i++){
        printf("%i ",arr1[i]);
    }
    printf("\nArray 2 :\n");
    for(int i = 0; i<5;i++){
        printf("%i ",arr2[i]);
    }
int i = 0, j = 0, k = 0;
    while (i < 5 && j < 5) {
        if (arr1[i] >= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < 5) {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < 5) {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
    printf("\nArray 3 :\n");
    for(int i = 0; i<10;i++){
        printf("%i ",arr3[i]);
    }*/
    /*int arr[5], max = 0 , min = 10000;
    for(int i = 0; i<5;i++){
        scanf("%i",&arr[i]);
    }
    for(int i = 0; i < 5 ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("Max = %i\nMin = %i",max,min);
    */
    /*int arr[10] = {1,1,1,2,3,4,5,5,8,8};
    for(int i = 0; i<10;i++){
            int isUnique = 1;
        for(int j = 0 ;j < i;j++){
            if(arr[i] == arr[j]){
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }*/
    return 0;
}

    return 0;
}
