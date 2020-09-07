#include "sort.h"

void PercDown(ElementType A[],int P,int N){
    int Parent,Child;
    ElementType X;
    X=A[P];
    for (Parent=P; Parent*2+1<N; Parent=Child) {
        Child=Parent*2+1;
        if (Child!=(N-1) && A[Child]<A[Child+1]) {
            Child++;
        }
        if (X>=A[Child])
            break;
        else
            A[Parent]=A[Child];
    }
    A[Parent]=X;
}

void Heap_Sort(ElementType A[],int N){
    ElementType *Arr=Duplication(A, N);
    int i;
    for (i=N/2-1; i>=0; i--) //建立最大堆
        PercDown(Arr, i, N);
    for (i=N-1; i>0; i--) {  //(删除最大值)将最大值放最后
        Swap(&Arr[0], &Arr[i]);
        PercDown(Arr, 0, i);
    }
//    PrintArray(Arr, N);
    free(Arr);
}
