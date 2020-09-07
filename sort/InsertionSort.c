#include"sort.h"

void Insertion_Sort(ElementType A[],int N){
    //进行N-1次
    //时间复杂度：  最小O(N)       最大O(N2)
    //           最好情况：顺序   最坏情况：逆序
    //稳定性：稳定
    ElementType *Arr=Duplication(A, N);
    int i,P;
    ElementType tmp;   /*要摸的下一张牌*/
    for (P=1; P<N; P++) {
        tmp=Arr[P];
        for (i=P; i>=1 && Arr[i-1]>tmp; i--)
            Arr[i]=Arr[i-1];
        Arr[i]=tmp;
    }
//    PrintArray(Arr, N);
    free(Arr);
}





void InsertionSort(int*a,int size){
    int i,j,tmp;//优化后的插入排序
    for (i=1; i<size; i++) {
        tmp=a[i];
        for (j=i-1; j>=0 && tmp<a[j]; j--) {
            a[j+1]=a[j];
        }
        a[j+1]=tmp;
    }
}
