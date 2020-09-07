#include"sort.h"

void Shell_Sort(ElementType A[],int N){
    ElementType *Arr=Duplication(A, N);
    int D,P,i;
    ElementType tmp;
    for (D=N/2; D>0; D/=2) {
        for (P=D; P<N; P++) {
            tmp=Arr[P];
            for (i=P; i>=D && Arr[i-D]>tmp; i-=D)
                Arr[i]=Arr[i-D];
            Arr[i]=tmp;
        }
    }
//    PrintArray(Arr, N);
    free(Arr);
}




void ShellSort(int *a,int size){
    int *arr;
    arr=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++) {
        arr[i]=0;
    }
    for (int i=0; i<size; i++) {
        arr[i]=a[i];
    }
    int gap;
//    int tmp;
    for (gap=size/2; gap>0; gap/=2) {
        int i,j;
        for (i=gap; i<size; i++) {
            for (j=i-gap; j>=0; j-=gap) {
                int min=0;
                if (arr[j+gap]<arr[j]) {
                    min=arr[j+gap];
                    arr[j+gap]=arr[j];
                    arr[j]=min;
                }
            }
        }
    }
//    printf("Result of ShellSort2=\n");
//    for (int i=0; i<size; i++) {
//        printf("%d ",a5[i]);
//    }printf("\n");
    free(arr);
}


void ShellSort2(int *a,int size){
    int *arr;
    arr=(int*)malloc(size*sizeof(int));
    for (int i=0; i<size; i++) {
        arr[i]=0;
    }
    for (int i=0; i<size; i++) {
        arr[i]=a[i];
    }
    int gap;
    int tmp;
    for (gap=size/2; gap>0; gap/=2) {
        int i,j;
        for (i=gap; i<size; i++) {
            tmp=arr[i];
            for (j=i-gap; j>=0 && tmp<arr[j]; j-=gap) {
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=tmp;
        }
    }
//    printf("Result of ShellSort=\n");
//    for (int i=0; i<size; i++) {
//        printf("%d ",a4[i]);
//    }printf("\n");
    free(arr);
}
