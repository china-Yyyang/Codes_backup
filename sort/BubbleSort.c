#include"sort.h"

void Bubble_Sort(ElementType A[],int N){  //仍是传地址
    //进行N-1次，每次选出一个最大的放最后
    //时间复杂度： 最小O(N)  最大O(N2)
    //注：flag=0取最小  最多进行N(N-1)/2次
    //稳定性：稳定
    ElementType *Arr=Duplication(A, N);
    
    int i,j,flag;
    for (i=N-1; i>=0; i--){
        flag=0;
        for (j=0; j<i; j++) {
            if (Arr[j]>Arr[j+1]){
                Swap(&Arr[j], &Arr[j+1]);
                flag=1;
            }
        }
        if (flag==0)
            break;
    }
//    PrintArray(Arr, N);
    free(Arr);
}





void BubbleSort(int *a,int size){
    int *arr;
    arr=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++) {
        arr[i]=0;
    }
    for (int i=0; i<size; i++) {
        arr[i]=a[i];
    }
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-1; j++) {
            int min=0;
            if (arr[j]>arr[j+1]) {
                min=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=min;
            }
        }
    }
//    printf("Result of BubbleSort=\n");
//    for (int i=0; i<size; i++) {
//        printf("%d ",arr[i]);
//    }printf("\n");
    free(arr);
}


void BubbleSortswap(int *a,int size){
    int *arr;
    arr=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++) {
        arr[i]=0;
    }
    for (int i=0; i<size; i++) {
        arr[i]=a[i];
    }
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-1; j++) {
            if (arr[j]>arr[j+1]) {
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
//    printf("Result of BubbleSort=\n");
//    for (int i=0; i<size; i++) {
//        printf("%d ",arr[i]);
//    }printf("\n");
    free(arr);
}
