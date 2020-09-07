//
//  Graph.h
//  Graph
//
//  Created by 曾加祥 on 2020/6/1.
//  Copyright © 2020 kevin. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//extern bool Visited[];

/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
    DataType Data[MaxVertexNum];      /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
MGraph CreateGraph( int VertexNum );
void InsertEdge( MGraph Graph, Edge E );
MGraph BuildGraph(void);

// 图的邻接表表示法
//#define MaxVertexNum 100    /* 最大顶点数设为100 */
//typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
//typedef int WeightType;        /* 边的权值设为整型 */
//typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

///* 边的定义 */
//typedef struct LENode *LEdge;
//struct LENode{
//    Vertex V1, V2;      /* 有向边<V1, V2> */
//    WeightType Weight;  /* 权重 */
//};

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    WeightType Weight;  /* 边权重 */
    PtrToAdjVNode Next;    /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;/* 边表头指针 */
    DataType Data;            /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
} AdjList[MaxVertexNum];    /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct LGNode *LGraph;
struct LGNode{
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};


LGraph CreateLGraph( int VertexNum );
void InsertLEdge( LGraph Graph, Edge E );
LGraph BuildLGraph(void);

#endif /* Graph_h */
