#include "AVL_Tree.h"

//返回两个数的较大值
int Max(int a,int b){
    return a>b? a:b;
}
//求树的深度
int GetHeight(AVLTree A){
    int LHeight,RHeight;
    if (A) {
        LHeight=GetHeight(A->Left);
        RHeight=GetHeight(A->Right);
        return (LHeight>RHeight? LHeight:RHeight)+ 1 ;
    }else return 0;
}

//LL旋转
AVLTree LL_Rotation(AVLTree A){  /* 注意：A必须有一个左子结点B */  /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
    AVLTree B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=Max(GetHeight(A->Left), GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left), A->Height)+1;
    return B;
}
//RR旋转
AVLTree RR_Rotation(AVLTree A){
    AVLTree B=A->Right;
    A->Right=B->Left;
    B->Left=A;
    A->Height=Max(GetHeight(A->Left), GetHeight(A->Right))+1;
    B->Height=Max(A->Height, GetHeight(B->Right))+1;
    return B;
}
//LR旋转
AVLTree LR_Rotation(AVLTree A){
    /*A必须有一个左子节点B，且B必须有一个右子节点C*/
    A->Left=RR_Rotation(A->Left);
    return LL_Rotation(A);
}
//RL旋转
AVLTree RL_Rotation(AVLTree A){
    A->Right=LL_Rotation(A->Right);
    return RR_Rotation(A);
}

//平衡二叉树插入
AVLTree AVL_Insert(AVLTree T,int X){
    if (!T) {
        T=(AVLTree)malloc(sizeof(AVLTree));
        T->Data=X;
        T->Height=0;
        T->Left=T->Right=NULL;
    }else if (X<T->Data){
        T->Left=AVL_Insert(T->Left, X);
        if (GetHeight(T->Left)-GetHeight(T->Right)==2) {
            if (X<T->Left->Data)
                T=LL_Rotation(T);
            else
                T=LR_Rotation(T);
        }
    }else if (X>T->Data){
        T->Right=AVL_Insert(T->Right, X);
        if (GetHeight(T->Left)-GetHeight(T->Right)==-2) {
            if (X>T->Right->Data)
                T=RR_Rotation(T);
            else
                T=RL_Rotation(T);
        }
    }/* else X == T->Data，无须插入 */
    T->Height=Max(GetHeight(T->Left), GetHeight(T->Right))+1;
    return T;
}

//遍历

