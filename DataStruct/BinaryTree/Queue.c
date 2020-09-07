//用链表构造队列
#include "DataStruct.h"
//
//Queue CreateQueue(void){
//    Queue Q;
//    Q=(Queue)malloc(sizeof(Queue));
//    Q->Front=Q->Rear=NULL;
//    return Q;
//}
//
//bool IsEmptyForQueue(Queue Q){
//    return (Q->Front==NULL);
//}
//
//void InsertQueueNode(Queue Q,BinTree Element){   //注意初始添加节点和之后添加节点的区别
//    Qelement tmp;
//    tmp=(Qelement)malloc(sizeof(Qelement));
//    if (tmp==NULL) {
//        return;
//    }
//    tmp->Data=Element;
//    tmp->Next=NULL;
//    if (Q->Rear==NULL) {
//        Q->Front=Q->Rear=tmp;
//    }
//    else{
//        Q->Rear->Next=tmp;
//        Q->Rear=tmp;
//    }
//}
//
//BinTree DeleteQueueNode(Queue Q){      //注意分类讨论
//    if (IsEmptyForQueue(Q))
//        return NULL;
//    Qelement Firstcell=Q->Front;
//    BinTree element=Firstcell->Data;
//    if(Q->Front==Q->Rear){
//        Q->Front=Q->Rear=NULL;
//        free(Firstcell);
//    }
//    else{
//        Firstcell=Q->Front;
//        Q->Front=Q->Front->Next;
//        free(Firstcell);
//    }
//    return element;
//}

//

//用数组实现队列       注：使用取余法让数组变成一个”圈“

AQueue CreateQueueByArr( int MaxSize )
{
    AQueue Q = (AQueue)malloc(sizeof(AQueue));
    Q->Data = (BinTree*)malloc(MaxSize * sizeof(BinTree*));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool IsFull( AQueue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

bool AddQ( AQueue Q, BinTree X )
{
    if ( IsFull(Q) ) {
        printf("队列满");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;          //数组值不是地址！！！
        return true;
    }
}

bool IsEmpty( AQueue Q )
{
    return (Q->Front == Q->Rear);
}

BinTree DeleteQ( AQueue Q )
{
    if ( IsEmpty(Q) ) {
        printf("队列空");
        return NULL;
    }
    else  {
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}
