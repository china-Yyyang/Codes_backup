#include"sort.h"


ElementType Median3(ElementType A[],int left,int right){
    int center=(left+right)/2;
    if (A[left]>A[center])  Swap(&A[left], &A[center]);
    if (A[left]>A[right])   Swap(&A[left], &A[right]);
    if (A[center]>A[right]) Swap(&A[center], &A[right]);
    /* 此时A[Left] <= A[Center] <= A[Right] */
    Swap(&A[center], &A[right-1]);/* 将基准Pivot藏到右边的倒数第二个*/
    return A[right-1];
}

void QSort(ElementType A[],int left,int right){
    int Pivot,Low,High,Cutoff;
    Cutoff=20;
    if (right-left>Cutoff) {
        Pivot=Median3(A, left, right);
        Low=left;High=right-1;
        while (1) {
            while (A[++Low]<Pivot);
            while (A[--High]>Pivot);
            if (Low<High)   Swap(&A[Low], &A[High]);
            else break;
        }
        Swap(&A[Low], &A[right-1]);
        QSort(A, left, Low-1);
        QSort(A, Low+1, right);
    }
    else    InsertionSort(A+left, right-left+1);  //元素太少用简单排序，如插入排序
        //注意不能调用Insertion_Sort，因为这个插入排序内部会复制该数组，在复制的数组中排序，从而无法达到调用该函数的目的
        //注意A+left就是指针
}
void Quick_Sort(ElementType A[],int N){ //统一接口
    ElementType *Arr=Duplication(A, N);
    QSort(Arr, 0, N-1);
//    PrintArray(Arr, N);
    free(Arr);
}



///* 快速排序 - 直接调用库函数 */
//
//#include <stdlib.h>
//
///*---------------简单整数排序--------------------*/
//int compare(const void *a, const void *b)
//{ /* 比较两整数。非降序排列 */
//    return (*(int*)a - *(int*)b);
//}
///* 调用接口 */
//qsort(A, N, sizeof(int), compare);
//
///*---------------简单整数排序--------------------*/
//
//
///*--------------- 一般情况下，对结构体Node中的某键值key排序 ---------------*/
//struct Node {
//    int key1, key2;
//} A[MAXN];
//
//int compare2keys(const void *a, const void *b)
//{ /* 比较两种键值：按key1非升序排列；如果key1相等，则按key2非降序排列 */
//    int k;
//    if ( ((const struct Node*)a)->key1 < ((const struct Node*)b)->key1 )
//        k = 1;
//    else if ( ((const struct Node*)a)->key1 > ((const struct Node*)b)->key1 )
//        k = -1;
//    else { /* 如果key1相等 */
//        if ( ((const struct Node*)a)->key2 < ((const struct Node*)b)->key2 )
//            k = -1;
//        else
//            k = 1;
//    }
//    return k;
//}
///* 调用接口 */
//qsort(A, N, sizeof(struct Node), compare2keys);
//
///*--------------- 一般情况下，对结构体Node中的某键值key排序 ---------------*/








void QuickSort(int *arr,int low,int high){
    int i=low;
    int j=high;
    int key=arr[low];
    if (low>=high) {
        return;
    }
    
    while (low<high) {
        while(low<high && key<=arr[high]){
            --high;
        }
        if (key>arr[high]) {
            Swap(&arr[low], &arr[high]);
            ++low;
        }
        while (low<high && key>=arr[low]) {
            ++low;
        }
        if (key<arr[low]) {
            Swap(&arr[low], &arr[high]);
            --high;
        }
    }
    QuickSort(arr, i, low-1);
    QuickSort(arr, low+1, j);
}
