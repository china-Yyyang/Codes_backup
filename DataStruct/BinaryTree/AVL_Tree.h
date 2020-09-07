#ifndef AVL_Tree_h
#define AVL_Tree_h

#include <stdio.h>
#include <stdlib.h>
typedef struct AVLNode *AVLTree;
struct AVLNode{
    int Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
int Max(int a,int b);
int GetHeight(AVLTree A);
AVLTree LL_Rotation(AVLTree A);
AVLTree RR_Rotation(AVLTree A);
AVLTree LR_Rotation(AVLTree A);
AVLTree RL_Rotation(AVLTree A);
AVLTree AVL_Insert(AVLTree T,int X);
#endif /* AVL_Tree_h */
