#include"sort.h"

ElementType* CreateArray(int N){
    static int *a;
    a=(int*)malloc(N*sizeof(int));
    for (int i=0; i<N; i++) {
        a[i]=0;
    }
//    static int a[10];
    srand((unsigned)time(NULL));
    for (int i=0; i<N; i++) {
        a[i]=rand();
    }
    return a;
}

void Swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

ElementType* Duplication(ElementType A[],int N){
    ElementType *Arr=(ElementType*)malloc(N*sizeof(ElementType));
    for (int i=0; i<N; i++) {
        Arr[i]=A[i];
    }
    return Arr;
}

void PrintArray(ElementType A[],int N){
    for (int i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");
}

void Clock(FunType fp,ElementType A[],int N){
    clock_t start_t,finish_t;double total_t;
    start_t=clock();
    fp(A,N);
    finish_t=clock();
    total_t=(double)(finish_t-start_t)/CLOCKS_PER_SEC;
    printf("%lfs\n",total_t);
}

double ClockForAverage(FunType fp,ElementType A[],int N){
    clock_t start_t,finish_t;double total_t;
    start_t=clock();
    fp(A,N);
    finish_t=clock();
    total_t=(double)(finish_t-start_t)/CLOCKS_PER_SEC;
    return total_t;
}
void Average(double T[],int N){
    double sum,average;
    sum=0;
    for (int i=0; i<N; i++)
        sum+=T[i];
    average=sum/N;
    printf("%d次排序平均时间：%lf\n",N,average);
}
