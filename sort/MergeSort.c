#include"sort.h"

/*          递归版           */
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd){
    int LeftEnd=R-1;
    int NumElements=RightEnd-L+1;
    int Tmp=L;   //存放数组的初始位置
    while (L<=LeftEnd && R<=RightEnd) {
        if (A[L]<=A[R])  //必须用<=要保证其稳定性
            TmpA[Tmp++]=A[L++];
        else
            TmpA[Tmp++]=A[R++];
    }
    while (L<=LeftEnd) //不能if,因为一侧可能都没有复制，需要用while循环；而且两个while循环只会执行一个
        TmpA[Tmp++]=A[L++];
    while (R<=RightEnd)
        TmpA[Tmp++]=A[R++];
    for (int i=0;i<NumElements;i++,RightEnd--)
        //这一部将排序好的放入原数组  为什么用RightEnd因为数组下标只有他没变
        //事实上由于我们不能改变原数组，这一步不可以省略
        A[RightEnd]=TmpA[RightEnd];
}
void MSort(ElementType A[],ElementType TmpA[],int L,int RightEnd){
    int Center;
    if (L<RightEnd) {
        Center=(RightEnd+L)/2;
        MSort(A, TmpA, L, Center);
        MSort(A, TmpA, Center+1, RightEnd);
        Merge(A, TmpA, L, Center+1, RightEnd);
    }
}
void Merge_Recursive_Sort(ElementType A[],int N){ //统一接口
    ElementType *Arr,*TmpA;
    Arr=Duplication(A, N);
    TmpA=(ElementType*)malloc(N*sizeof(ElementType));
    MSort(Arr, TmpA, 0, N-1);
    
//    PrintArray(Arr, N);
    free(Arr);
    free(TmpA);
}


/*           非递归版            */
void Merge2(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd){
    int LeftEnd=R-1;
    int Tmp=L;   //存放数组的初始位置
    while (L<=LeftEnd && R<=RightEnd) {
        if (A[L]<=A[R])  //必须用<=要保证其稳定性
            TmpA[Tmp++]=A[L++];
        else
            TmpA[Tmp++]=A[R++];
    }
    while (L<=LeftEnd) //不能if,因为一侧可能都没有复制，需要用while循环；而且两个while循环只会执行一个
        TmpA[Tmp++]=A[L++];
    while (R<=RightEnd)
        TmpA[Tmp++]=A[R++];
}
void Merge_pass(ElementType A[],ElementType TmpA[],int N,int length){
    int i,j;
    for (i=0; i<=N-2*length; i+=2*length)
        Merge2(A, TmpA, i, i+length, i+2*length-1);
    if (i+length<N)
        Merge2(A, TmpA, i, i+length, N-1);
    else
        for (j=i;j<N;j++)
            TmpA[j]=A[j];
}
void Merge_NonRecursive_Sort(ElementType A[],int N){
    int length;
    ElementType *TmpA,*Arr;
    TmpA=(ElementType*)malloc(N*sizeof(ElementType));
    Arr=(ElementType*)malloc(N*sizeof(ElementType));
    Arr=Duplication(A, N);
    length=1;
    if (TmpA!=NULL && Arr!=NULL) {
        while (length<N) {
            Merge_pass(Arr, TmpA, N, length);
            length*=2;
            Merge_pass(TmpA, Arr, N, length);
            length*=2;
        }
//        PrintArray(Arr, N);
        free(TmpA);
        free(Arr);
    }else
        printf("空间不足");
}










void MergeAdd(int arr[], int left, int mid, int right, int *temp){//实现“治”
    int i = left;
    int j = mid + 1;
    int k = left;//临时下标
    while (i <= mid&&j <= right){
        if (arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
    //把temp中的内容拷给arr数组中
    //进行归并的时候，处理的区间是arr[left,right),对应的会把这部分区间的数组填到tmp[left,right)区间上
    memcpy(arr + left, temp + left, sizeof(int)*(right - left+1));
}

void MergeSort(int arr[],int left,int right,int *temp){//实现“分”
    int mid = 0;
    if (left < right){
        mid = left + (right - left) / 2;
        MergeSort(arr, left, mid, temp);
        MergeSort(arr, mid + 1, right, temp);
        MergeAdd(arr, left, mid, right, temp);
    }
}

//int main(){
//    int arr[] = {8,4,5,7,1,3,6,2};
//    int len = sizeof(arr)/sizeof(arr[0]);
//    int *temp = (int*)malloc(sizeof(int)*len);
//    MergeSort(arr, 0, len - 1, temp);
//    free(temp);
//    for (int i = 0; i < len; i++){
//        printf("%d ", arr[i]);
//    }
//    system("pause");
//    return 0;
//}
//
