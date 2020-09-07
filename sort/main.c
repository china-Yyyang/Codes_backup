

//排序算法
#include"sort.h"
int N;
int main(){
    int *A;
    printf("N=");
    scanf("%d",&N);
    A=CreateArray(N);
//    printf("Ranmdom array=\n");
//    PrintArray(A, N);
    
    //计时
    char *Name[]={"Bubble_Sort","Insertion_Sort","Shell_Sort","Heap_Sort","Merge_Recursive_Sort","Quick_Sort"};
    FunType Func[]={Bubble_Sort,Insertion_Sort,Shell_Sort,Heap_Sort,Merge_Recursive_Sort,Quick_Sort};
    for (int i=2; i<6; i++) {
        printf("%-20s CPU用时：",Name[i]);
        Clock(Func[i], A, N);
    }
    int compare(const void *a,const void *b);
    clock_t s,f;
    s=clock();
    qsort(A, N, sizeof(int), compare);
    f=clock();
    double t=(double)(f-s)/CLOCKS_PER_SEC;
    printf("%lf\n",t);
    //求100次排序的平均值
//    double T[100];
//    for (int i=0; i<100; i++)
//        T[i]=ClockForAverage(Quick_Sort, A, size);
//    Average(T, 100);

//     PrintArray(A, N);
    free(A);
    
    
    return 0;
}

int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
