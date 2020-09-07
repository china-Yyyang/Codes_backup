#include "Graph.h"


/*      DFS和BFS算法    注：分别用邻接矩阵和邻接表实现*/
#define MaxVisitedNum 100
bool Visited[MaxVisitedNum]={false};
#define ERROR -1
//#define Maxsize 100

//链表 实现队列
typedef struct node *Qelement;
struct node{
    Vertex Data;
    struct node *Next;
};

typedef struct Qnode *Queue;
struct Qnode{
    Qelement Front;
    Qelement Rear;
};

Queue CreateQueue(void){
    Queue Q;
    Q=(Queue)malloc(sizeof(Queue));
    Q->Front=Q->Rear=NULL;
    return Q;
}

bool IsEmpty(Queue Q){
    return (Q->Front==NULL);
}

void Enqueue(Queue Q, Vertex V){
    Qelement Tmp;
    Tmp=(Qelement)malloc(sizeof(Qelement));
    if (Tmp==NULL)
        return;
    Tmp->Data=V;
    Tmp->Next=NULL;
    if (Q->Rear==NULL) {
        Q->Front=Q->Rear=Tmp;
    }else{
        Q->Rear->Next=Tmp;
        Q->Rear=Tmp;
    }
}
Vertex Dequeue(Queue Q){
    if (IsEmpty(Q))
        return ERROR;
    Qelement Firstcell=Q->Front;
    Vertex V=Firstcell->Data;
    if (Q->Front==Q->Rear) {
        Q->Front=Q->Rear=NULL;
        free(Firstcell);
    }else{
        Q->Front=Q->Front->Next;
        free(Firstcell);
    }
    return V;
}
void Visit(Vertex V){
    printf("正在访问的节点是%d\n",V);
}

struct stack{       //堆栈
    int Data;
    struct stack *Next;
};
typedef struct stack* Stack;
Stack CreateStackByLink(void){
    Stack S;
    S=(Stack)malloc(sizeof(Stack));
    S->Next=NULL;
    return S;
}

bool IsEmptyForStack(Stack S){
    return (S->Next==NULL);
}

void Push(Stack S,int Element){
    Stack tmp;
    tmp=(Stack)malloc(sizeof(Stack));
    if (tmp==NULL) {
        return;
    }
    tmp->Data=Element;
    tmp->Next=S->Next;
    S->Next=tmp;
}

int Pop(Stack S){
    if (IsEmptyForStack(S)) {
        printf("堆栈空");
        return -1;
    }
    else{
    Stack Firstcell;
    int Element;
    Firstcell=S->Next;
    Element=Firstcell->Data;
    S->Next=Firstcell->Next;
    free(Firstcell);
    return Element;
    }
}



///*邻接表DFS*/     //记得将Graph.h和Graph.c中 邻接矩阵 的内容注释掉
//
//
//void DFS(LGraph Graph,Vertex V,void (*Visit)(Vertex)){
//    PtrToAdjVNode W;
//    Visit(V);
//    Visited[V]=true;
//    for (W=Graph->G[V].FirstEdge; W; W=W->Next) {
//        if (!Visited[W->AdjV])
//            DFS(Graph, W->AdjV, Visit);
//    }
//}
//
//void BFS(LGraph Graph, Vertex StartV){
//    Queue Q;
//    Vertex V;
//    PtrToAdjVNode W;
//    Q=CreateQueue();
//    Visit(StartV);
//    Visited[StartV]=true;
//    Enqueue(Q, StartV);
//    while (!IsEmpty(Q)) {
//        V=Dequeue(Q);
//        for (W=Graph->G[V].FirstEdge; W;W=W->Next ) {
//            if (!Visited[W->AdjV]) {
//                Visit(W->AdjV);
//                Visited[W->AdjV]=true;
//                Enqueue(Q, W->AdjV);
//            }
//        }
//    }
//}


/*邻接矩阵DFS*/     //记得将Graph.h和Graph.c中 邻接表 的内容注释掉
//bool Visited[]={false};

bool IsEdge(MGraph Graph,Vertex V,Vertex W){
    return Graph->G[V][W]<INFINITY? true:false;
}

void DFS(MGraph Graph,Vertex V){
    Vertex W;
    Visit(V);
    Visited[V]=true;
    for (W=0; W<Graph->Nv; W++) {
        if (!Visited[W] && IsEdge(Graph, V, W)) {
            DFS(Graph, W);
        }
    }
}

void BFS(MGraph Graph,Vertex StartV){
    Queue Q;
    Vertex V,W;
    Q=CreateQueue();
    Visit(StartV);
    Visited[StartV]=true;
    Enqueue(Q, StartV);
    while (!IsEmpty(Q)) {
        V=Dequeue(Q);
        for (W=0; W<Graph->Nv; W++) {
            if (!Visited[W]&&IsEdge(Graph, V, W)) {
                Visit(W);
                Visited[W]=true;
                Enqueue(Q, W);
            }
        }
    }
}







/*     最短路径问题    */

// 算法1：无权图的单源最短路径       注：邻接矩阵表示图
int SDist[7];
int Path[7];
void UnweightedSingleSourceShortestPath(MGraph Graph,Vertex S){
    Queue Q;
    Vertex V,W;
    Q=CreateQueue();
    Enqueue(Q, S);
    while (!IsEmpty(Q)) {
        V=Dequeue(Q);
        for (W=0; W<Graph->Nv; W++) {
            if (SDist[W]==-1 && Graph->G[V][W]!=INFINITY) {
                SDist[W]=SDist[V]+1;
                Path[W]=V;
                Enqueue(Q, W);
            }
        }
    }
}
//// 算法1：测试代码
//int main(){
//    MGraph Graph;
//    Graph=CreateGraph(7);
//    Graph->G[0][1]=1;
//    Graph->G[0][3]=1;
//    Graph->G[1][3]=1;
//    Graph->G[1][4]=1;
//    Graph->G[2][0]=1;
//    Graph->G[2][5]=1;
//    Graph->G[3][2]=1;
//    Graph->G[3][4]=1;
//    Graph->G[3][5]=1;
//    Graph->G[3][6]=1;
//    Graph->G[4][6]=1;
//    Graph->G[6][5]=1;
//
//    Graph->Ne=12;
//    for (int i=0; i<7; i++){
//        SDist[i]=-1;
//        Path[i]=-1;
//    }
//
//    Vertex S=3;
//    SDist[S-1]=0;
//    UnweightedSingleSourceShortestPath(Graph, S-1);
//    for (int i=0; i<7; i++) {
//        printf("%d\t",SDist[i]);
//    }printf("\n");
//    for (int i=0; i<7; i++) {
//        printf("%d\t",Path[i]);   //注:此时下表从0开始
//    }
//    printf("\n");
//
//    Stack stack=CreateStackByLink();
//    Vertex index=4;
//    Vertex rindex=index-1;
//    Push(stack, index);
//    while (Path[rindex]!=-1) {
//        Push(stack, Path[rindex]+1);
//        rindex=Path[rindex];
//    }
//    while (!IsEmptyForStack(stack)) {
//        printf("%d\t",Pop(stack));
//    }
//    return 0;
//}


// 算法2：有权图的单源最短路径        注：用邻接矩阵标示图
Vertex FindMinDist_Dijkstra(MGraph Graph,WeightType dist[],bool collected[]){
    /* 返回”未被收录者“顶点中的最小值 */
    Vertex V,MinV=-1;  //事实上不用初始化，这里是为了防止报错
    WeightType Mindist=INFINITY;
    for (V=0; V<Graph->Nv; V++) {
        if (collected[V]==false && dist[V]<Mindist) {
            Mindist=dist[V];
            MinV=V;
        }
    }
    if (Mindist<INFINITY) {
        return MinV;
    }
    else return ERROR;
}

bool Dijkstra(MGraph Graph,WeightType dist[],Vertex path[],Vertex S){
    Vertex V,W;
    bool collected[MaxVertexNum];
    //初始化   将S标记为true，并将S及其邻接点实际在dist和path上记录     
    for (V=0; V<Graph->Nv; V++) {
        dist[V]=Graph->G[S][V];
        if (dist[V]<INFINITY)
            path[V]=S;
        else
            path[V]=-1;
        collected[V]=false;
    }
    dist[S]=0;
    collected[S]=true;
    while (1) {
        V=FindMinDist_Dijkstra(Graph, dist, collected);
        if (V==ERROR)  //如果V不存在，算法结束
            break;
        collected[V]=true;
        for (W=0; W<Graph->Nv; W++) {
            if (collected[W]==false && Graph->G[V][W]<INFINITY) {
                if (Graph->G[V][W]<0)  //排除负边
                    return false;
                if (dist[V]+Graph->G[V][W]<dist[W]) {
                    dist[W]=dist[V]+Graph->G[V][W];
                    path[W]=V;
                }
            }
        }
    }
    return true;
}


// 算法3：多源最短路算法   注：邻接矩阵存储

bool Floyd(MGraph Graph,WeightType D[][MaxVertexNum],Vertex P[][MaxVertexNum]){
    //时间复杂度O(N3)
    //初始化:带权的邻接矩阵，对角元是0，其他为正无穷
    Vertex i,j,k;
    for (i=0; i<Graph->Nv; i++) {
        for (j=0; j<Graph->Nv; j++) {
            D[i][j]=Graph->G[i][j];
            P[i][j]=-1;
        }
    }
    for (k=0; k<Graph->Nv; k++) {
        for (i=0; i<Graph->Nv; i++) {
            for (j=0; j<Graph->Nv; j++) {
                if (D[i][j]<0)
                    return false;
                if (D[i][k]+D[k][j]<D[i][j]) {
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=k;
                }
            }
        }
    }
    return true;
}

//int main(){
//    bool collected[10]={false};
//    for (int i=0; i<10; i++) {
//        if (collected[i]==false) {
//            printf("%d\t",i);
//        }
//    }
//    return 0;
//}



/*     最小生成树(MST)    */

//算法1；Prim算法
Vertex FinMinDist_Prim(MGraph Graph,WeightType dist[]){   //时间复杂度O(V2)
    Vertex V,MinV=-1;
    WeightType MinDist=INFINITY;
    for (V=0; V<Graph->Nv; V++) {
        if (dist[V]!=0 && dist[V]<MinDist) {
            MinDist=dist[V];
            MinV=V;
        }
    }
    if (MinDist<INFINITY)
        return MinV;
    else
        return ERROR;
}

int Prim(MGraph Graph,LGraph MST){
    //初始化
    WeightType dist[MaxVertexNum],TotalWeight;//这里的dist是节点到树的距离
    Vertex parent[MaxVertexNum],V,W;
    Edge E;
    int VCount;
    for (V=0; V<Graph->Nv; V++) {
        dist[V]=Graph->G[0][V];
        parent[V]=0;  //这一步事实上已经把开始节点(即V0)的邻接点初始化了
    }
    TotalWeight=0;VCount=0;
//    MST=CreateLGraph(Graph->Nv);
    E=(Edge)malloc(sizeof(Edge)); //建立空的边节点，为后面插入做准备
    dist[0]=0;
    parent[0]=-1;
    VCount++;
    while (1) {
        V=FinMinDist_Prim(Graph, dist);
        if (V==ERROR)
            break;
        E->V1=parent[V];
        E->V2=V;
        E->Weight=dist[V];
        InsertLEdge(MST, E);
        TotalWeight+=dist[V];
        dist[V]=0;
        VCount++;
        for (W=0; W<Graph->Nv; W++) {
            if (dist[W]!=0 && Graph->G[V][W]<INFINITY) {
                if (Graph->G[V][W]<0){
                    printf("存在负值\n");
                    return ERROR;
                }
                if (Graph->G[V][W]<dist[W]) {
                    //若收录V使dist[W]变小
                    dist[W]=Graph->G[V][W];
                    parent[W]=V;
                }
            }
        }
    }
    if (VCount<Graph->Nv)
        TotalWeight=ERROR;
    return TotalWeight;
}

//int main(){
//    MGraph Graph=BuildGraph();
//    LGraph MST=(LGraph)malloc(sizeof(LGraph));
//    MST=CreateLGraph(Graph->Nv);
//    printf("TotalWeight=%d\n",Prim(Graph, MST));
//    MST->Nv=Graph->Nv-1;
//    printf("Nv=%d  Ne=%d\n",MST->Nv,MST->Ne);
//    return 0;
//}


//  算法2：Kruskal 最小生成树算法
/*-------------------- 顶点并查集定义 --------------------*/
typedef Vertex ElementType; /* 默认元素可以用非负整数表示 */
typedef Vertex SetName;     /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MaxVertexNum]; /* 假设集合元素下标从0开始 */
 
void InitializeVSet( SetType S, int N )
{ /* 初始化并查集 */
    int X;
    for ( X=0; X<N; X++ ) S[X] = -1;
}
 
void Union( SetType S, SetName Root1, SetName Root2 )
{ /* 这里默认Root1和Root2是不同集合的根结点 */
    /* 保证小集合并入大集合 */
    if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
        S[Root2] += S[Root1];     /* 集合1并入集合2  */
        S[Root1] = Root2;
    }
    else {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
    }
}
 
SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
    if ( S[X] < 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* 路径压缩 */
}
 
bool CheckCycle( SetType VSet, Vertex V1, Vertex V2 )
{ /* 检查连接V1和V2的边是否在现有的最小生成树子集中构成回路 */
    Vertex Root1, Root2;
 
    Root1 = Find( VSet, V1 ); /* 得到V1所属的连通集名称 */
    Root2 = Find( VSet, V2 ); /* 得到V2所属的连通集名称 */
 
    if( Root1==Root2 ) /* 若V1和V2已经连通，则该边不能要 */
        return false;
    else { /* 否则该边可以被收集，同时将V1和V2并入同一连通集 */
        Union( VSet, Root1, Root2 );
        return true;
    }
}
/*-------------------- 并查集定义结束 --------------------*/
 
/*-------------------- 边的最小堆定义 --------------------*/
void PercDown( Edge ESet, int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的边数组中以ESet[p]为根的子堆调整为关于Weight的最小堆 */
    int Parent, Child;
    struct ENode X;
 
    X = ESet[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1; //注意这里是从0开始计数
        if( (Child!=N-1) && (ESet[Child].Weight>ESet[Child+1].Weight) )
            Child++;  /* Child指向左右子结点的较小者 */
        if( X.Weight <= ESet[Child].Weight ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            ESet[Parent] = ESet[Child];
    }
    ESet[Parent] = X;
}
 
void InitializeESet( LGraph Graph, Edge ESet )
{ /* 将图的边存入数组ESet，并且初始化为最小堆 */
    Vertex V;
    PtrToAdjVNode W;
    int ECount;
 
    /* 将图的边存入数组ESet */
    ECount = 0;
    for ( V=0; V<Graph->Nv; V++ )
        for ( W=Graph->G[V].FirstEdge; W; W=W->Next )
            if ( V < W->AdjV ) { /* 避免重复录入无向图的边，只收V1<V2的边 */
                ESet[ECount].V1 = V;
                ESet[ECount].V2 = W->AdjV;
                ESet[ECount++].Weight = W->Weight;
            }
    /* 初始化为最小堆 */
    for ( ECount=Graph->Ne/2; ECount>=0; ECount-- )
        PercDown( ESet, ECount, Graph->Ne );
}
 
void Swap(Edge a,Edge b){
    struct ENode c;
    c=*a;*a=*b;*b=c;
}

int GetEdge( Edge ESet, int CurrentSize )
{ /* 给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 */
 
    /* 将最小边与当前堆的最后一个位置的边交换 */
    Swap( &ESet[0], &ESet[CurrentSize-1]);
    /* 将剩下的边继续调整成最小堆 */
    PercDown( ESet, 0, CurrentSize-1 );
 
    return CurrentSize-1; /* 返回最小边所在位置 */
}
/*-------------------- 最小堆定义结束 --------------------*/
 
 
int Kruskal( LGraph Graph, LGraph MST ) //时间复杂度 O(ELogE) 注：各模块不是嵌套的主要取决于最先对的建立
{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
    WeightType TotalWeight;
    int ECount, NextEdge;
    SetType VSet; /* 顶点数组 */
    Edge ESet;    /* 边数组 */  //事实上ESet是个指针
 
    InitializeVSet( VSet, Graph->Nv ); /* 初始化顶点并查集 */
    ESet = (Edge)malloc( sizeof(struct ENode)*Graph->Ne );
    InitializeESet( Graph, ESet ); /* 初始化边的最小堆 */
    /* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
    MST = CreateLGraph(Graph->Nv);
    TotalWeight = 0; /* 初始化权重和     */
    ECount = 0;      /* 初始化收录的边数 */
 
    NextEdge = Graph->Ne; /* 原始边集的规模 */
    while ( ECount < Graph->Nv-1 ) {  /* 当收集的边不足以构成树时 */
        NextEdge = GetEdge( ESet, NextEdge ); /* 从边集中得到最小边的位置 */
        if (NextEdge < 0) /* 边集已空 */
            break;
        /* 如果该边的加入不构成回路，即两端结点不属于同一连通集 */
        if ( CheckCycle( VSet, ESet[NextEdge].V1, ESet[NextEdge].V2 )==true ) {
            /* 将该边插入MST */
            InsertLEdge( MST, ESet+NextEdge );
            TotalWeight += ESet[NextEdge].Weight; /* 累计权重 */
            ECount++; /* 生成树中边数加1 */
        }
    }
    if ( ECount < Graph->Nv-1 )
        TotalWeight = -1; /* 设置错误标记，表示生成树不存在 */
 
    return TotalWeight;
}
