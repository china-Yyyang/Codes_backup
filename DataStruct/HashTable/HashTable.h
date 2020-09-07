
#ifndef HashTable_h
#define HashTable_h


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAXTABLESIZE 100000 /* 允许开辟的最大散列表长度 */
typedef int ElementType;    /* 关键词类型用整型 */
typedef int Index;          /* 散列地址类型 */
typedef Index Position;     /* 数据所在位置与散列地址是同一类型 */

/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty, Deleted } EntryType;
 
typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry{
    ElementType Data; /* 存放元素 */
    EntryType Info;   /* 单元状态 */
};
 
typedef struct TblNode *HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
    int TableSize; /* 表的最大长度 */
    Cell *Cells;   /* 存放散列单元数据的数组 */
};


//#define KEYLENGTH 15                   /* 关键词字符串的最大长度 */
//typedef char ElementType[KEYLENGTH+1]; /* 关键词类型用字符串 */
//typedef int Index;                     /* 散列地址类型 */
///******** 以下是单链表的定义 ********/
//typedef struct LNode *PtrToLNode;
//struct LNode {
//    ElementType Data;
//    PtrToLNode Next;
//};
//typedef PtrToLNode Position;
//typedef PtrToLNode List;
///******** 以上是单链表的定义 ********/
//
//typedef struct TblNode *HashTable; /* 散列表类型 */
//struct TblNode {   /* 散列表结点定义 */
//    int TableSize; /* 表的最大长度 */
//    List Heads;    /* 指向链表头结点的数组 */
//};

#endif /* HashTable_h */
