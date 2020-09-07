
#ifndef DataStruct_h
#define DataStruct_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Size 100
//#define MaxSize 10     //  没有”;“    注意更改

//结构体定义
struct binarytree{   //普通二叉树
    int Data;
    struct binarytree *Left;
    struct binarytree *Right;
};
typedef struct binarytree* BinTree;

struct stack{       //堆栈
    BinTree Data;
    struct stack *Next;
};
typedef struct stack* Stack;

struct node{            //链表实现对列
    BinTree Data;
    struct node *Next;
};
typedef struct node *Qelement;
struct Qnode{
    Qelement Rear;
    Qelement Front;
};
typedef struct Qnode *Queue;

typedef int Position;
struct QNode {          //数组实现队列
    BinTree *Data;          /* 存储元素的数组 */
    Position Front, Rear;    /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量 */
};
typedef struct QNode *AQueue;

//typedef struct AVLNode *AVLTree;
//struct AVLNode{
//    int Data;
//    AVLTree Left;
//    AVLTree Right;
//    int Height;
//};



//用链表实现堆栈的简单操作
Stack CreateStackByLink(void);
bool IsEmptyForStack(Stack S);
void Push(Stack S,BinTree Element);
BinTree Pop(Stack S);

////用链表实现对队列的简单操作
//Queue CreateQueueByLink(void);
//bool IsEmptyForQueue(Queue Q);
//void InsertQueueNode(Queue Q,BinTree Element);
//BinTree DeleteQueueNode(Queue Q);
//用数组实现对队列的简单操作
AQueue CreateQueueByArr( int MaxSize );
bool IsFull( AQueue Q );
bool IsEmpty( AQueue Q );
bool AddQ( AQueue Q, BinTree X );
BinTree DeleteQ( AQueue Q );

//二叉树遍历
void RecursionPreOrderTravesal(BinTree BT);
void RecursionInOrderTravesal(BinTree BT);
void RecursionPostOrderTravesal(BinTree BT);
void NRPreOrderTraversal( BinTree BT);
void NRInOrderTraversal( BinTree BT);
void NRPostorderTraversal( BinTree BT );
void LevelorderTraversal ( BinTree BT );
void PreOrderPrintLeaves(BinTree BT);
int PostOrderGetHeight(BinTree BT);
BinTree Copy(BinTree BT);
BinTree Find(BinTree BT,int element);
BinTree NRFind(BinTree BST,int element);
BinTree FindMin(BinTree BT);
BinTree FindMax(BinTree BST);
BinTree Insert(BinTree BST, int element);
BinTree Delete(BinTree BST, int element);


#endif /* DataSturct_h */
