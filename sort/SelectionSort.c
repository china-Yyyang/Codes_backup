#include<stdio.h>
#include<stdlib.h>
#include"sort.h"
void SelectionSort(int *a,int size){
    int *arr;
    arr=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++) {
        arr[i]=0;
    }
    for (int i=0; i<size; i++) {
        arr[i]=a[i];
    }
    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            int min=0;
            if (arr[i]>arr[j]) {    //如果array[i]比array[j]大交换两者的值的值
                min=arr[j];
                arr[j]=arr[i];
                arr[i]=min;
            }
        }
    }
//    printf("Result of Selection =\n");
//    for (int i=0; i<size; i++) {
//        printf("%d ",arr[i]);
//    }printf("\n");
    
}


void SelectionSort2(int *a,int size){
    int *arr;
    arr=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++) {
        arr[i]=0;
    }
    for (int i=0; i<size; i++) {
        arr[i]=a[i];
    }
    int i,j,k,tmp;
    for (i=0; i<size-1; i++) {
        k=i;
        for (j=i+1; j<size; j++) {
            if (arr[j]<arr[k]) {
                k=j;
            }
        }
        tmp=arr[k];
        arr[k]=arr[i];
        arr[i]=tmp;
    }
//    for (int i=0; i<size-1; i++) {
//        for (int j=i+1; j<size; j++) {
//            int min=0;
//            if (a2[i]>a2[j]) {    //如果array[i]比array[j]大交换两者的值的值
//                min=a2[j];
//                a2[j]=a2[i];
//                a2[i]=min;
//            }
//        }
//    }
//    printf("Result of Selection =\n");
//    for (int i=0; i<size; i++) {
//        printf("%d ",arr[i]);
//    }printf("\n");
    free(arr);
}
