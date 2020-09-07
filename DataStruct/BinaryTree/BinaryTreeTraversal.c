//二叉树遍历

#include "DataStruct.h"
/*----迭代法实现二叉树遍历----*/
void RecursionPreOrderTravesal(BinTree BT){
    if (!BT) {    //这个判断其实可以省去
        return;
    }
    else{
        printf("%5d",BT->Data);
        RecursionPreOrderTravesal(BT->Left);
        RecursionPreOrderTravesal(BT->Right);
    }
}
void RecursionInOrderTravesal(BinTree BT){
    if (BT) {
        RecursionInOrderTravesal(BT->Left);
        printf("%5d",BT->Data);
        RecursionInOrderTravesal(BT->Right);
    }
}
void RecursionPostOrderTravesal(BinTree BT){
    if (BT) {
        RecursionPostOrderTravesal(BT->Left);
        RecursionPostOrderTravesal(BT->Right);
        printf("%5d",BT->Data);
    }
}



/*----非迭代法实现二叉树遍历----*/
/*前序遍历*/
void NRPreOrderTraversal( BinTree BT){
    BinTree T = BT;
    Stack S = CreateStackByLink();
    while( T || !IsEmptyForStack(S) )
    {
        while(T)
        {
            Push(S,T);
            printf("%5d", T->Data);
            T = T->Left;
        }
        if( !IsEmptyForStack(S))
        {
            T = Pop(S); /* 先弹出结点 */
            T = T->Right;
        }
    }
}


/*中序遍历*/
void NRInOrderTraversal( BinTree BT){
    BinTree T = BT; 
    Stack S = CreateStackByLink();
    while( T || !IsEmptyForStack(S) )
    {
        while(T)
        {
            Push(S,T);
            T = T->Left;
        }
        if( !IsEmptyForStack(S))
        {
            T = Pop(S);
            printf("%5d", T->Data);
            T = T->Right;
        }
    }
}
    

/* 后序遍历 */
void NRPostorderTraversal( BinTree BT )
{
    BinTree T = BT, P = NULL; /* P上一个已被访问的结点 */
    Stack S = CreateStackByLink(); /*创建并初始化堆栈S*/
    while( T || !IsEmptyForStack(S) )/* 树不空或栈不空 */
    {
        while(T)/*一直向左并将沿途结点压入堆栈*/
        {
            Push(S,T);  /* 结点压栈(第一次遇到结点) */
            T = T->Left;/* 一直向左 */
        }
        if( !IsEmptyForStack(S))
        {
            T = Pop(S); /* 先弹出结点 */
            if(T->Right == P || T->Right == NULL)
            {   /* 右孩子已访问或右孩子不存在, 弹出结点 */
                printf("%5d", T->Data);  /* 访问结点 */
                P = T; /* P指向被访问结点 */
                T = NULL; /* 树置空(该树的左\右\根结点已经访问) */
            }
            else
            {
                Push(S,T); /* 否则,不应该弹出结点, 结点再次入栈 */
                T = T->Right;/* 继续遍历右子树 */
            }
        }
    }
}


/*----层序遍历----*/
void LevelorderTraversal ( BinTree BT )
{
    AQueue Q;
    BinTree T;
    if ( !BT ) return; /* 若是空树则直接返回 */
    Q = CreateQueueByArr(Size); /* 创建空队列Q */
    AddQ(Q, BT);
    while ( !IsEmpty(Q) ) {
        T = DeleteQ(Q);
        printf("%5d", T->Data ); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )   AddQ( Q, T->Right );
    }
}

//void LevelorderTraversalByStack ( BinTree BT )  //若用堆栈则实现右侧的前序遍历
//{
//    Stack Q;
//    BinTree T;
//    if ( !BT ) return; /* 若是空树则直接返回 */
//    Q = CreateStackByLink(); /* 创建空队列Q */
//    Push(Q, BT);
//    while ( !IsEmptyForStack(Q) ) {
//        T = Pop(Q);
//        printf("%5d", T->Data ); /* 访问取出队列的结点 */
//        if ( T->Left )   Push( Q, T->Left );
//        if ( T->Right )   Push( Q, T->Right );
//    }
//}

//访问叶节点
void PreOrderPrintLeaves(BinTree BT){
    if (BT) {
        if (!BT->Left && !BT->Right)
            printf("%5d",BT->Data);
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}

//求树的深度
int PostOrderGetHeight(BinTree BT){      
    int LHeight,RHeight,Max;
    if (BT) {
        LHeight=PostOrderGetHeight(BT->Left);
        RHeight=PostOrderGetHeight(BT->Right);
        Max=(LHeight>RHeight)? LHeight:RHeight;
        return Max+1;
    }
    else return 0;
}

//树的复制
BinTree Copy(BinTree BT){
    BinTree NewTree=NULL;
    if (BT) {
        NewTree=(BinTree)malloc(sizeof(BinTree));
        NewTree->Data=BT->Data;
        NewTree->Left=Copy(BT->Left);
        NewTree->Right=Copy(BT->Right);
    }
    return NewTree;
}


/*二叉搜索树*/
//二叉搜索树，找某元素的位置
BinTree Find(BinTree BST,int element){
    if (!BST)    return NULL;  //查找失败，即二叉树中不含所找元素，不是因为BT为空而加上这一句
    if (element>BST->Data)   return Find(BST->Right, element);
    else if (element<BST->Data)  return Find(BST->Left, element);
    else return BST;
}
//非递归版
BinTree NRFind(BinTree BST,int element){
    while (BST) {
        if (element>BST->Data)  BST=BST->Right;
        else if (element<BST->Data) BST=BST->Left;
        else    return BST;
    }
    return NULL;
}

//二叉搜索树，找最小值位置
BinTree FindMin(BinTree BST){
    if(!BST) return NULL; //因为判断条件从BT->Left开始，所以要满足BT不为空
    if (!BST->Left)  return BST;
    else    return FindMin(BST->Left);
}

//二叉搜索树，找最大值位置
BinTree FindMax(BinTree BST){
//    while (BST->Right) {     //如果BST为空会报错
//        if (BST)     BST=BST->Right;
//    }
    if (BST) {
        while (BST->Right)  BST=BST->Right;
    }
    return BST;
}

//二叉搜索树，插入某个节点。只会成为叶节点
BinTree Insert(BinTree BST, int element){
    if (!BST) {
        BST=(BinTree)malloc(sizeof(BinTree));
        BST->Data=element;
        BST->Left=BST->Right=NULL;
    }else{
        if (element<BST->Data)
            BST->Left=Insert(BST->Left, element); //将新节点与元BST连接，注意与BST查找相区分
        else if (element>BST->Data)
            BST->Right=Insert(BST->Right, element);
    }
    return BST;
}

//二叉搜索树，删除某个节点，要删除节点的子节点数量可能有2，1，0，注意分类讨论
BinTree Delete(BinTree BST, int element){
    BinTree Tmp;
    if (!BST)   printf("要删的元素没找到");
    else if (element<BST->Data)
        BST->Left=Delete(BST->Left, element);
    else if (element>BST->Data)
        BST->Right=Delete(BST->Right, element);
    else{
        if (BST->Left && BST->Right) {
            Tmp=FindMin(BST->Right);
            BST->Data=Tmp->Data;
            BST->Right=Delete(BST->Right, BST->Data);
        }else{
            Tmp=BST;
            if (!BST->Left)
                BST=BST->Right;
            else if (!BST->Right)
                BST=BST->Left;
            free(Tmp);
        }
//        free(Tmp);  //不能随便free掉Tmp
    }
    return BST;
}



/*      遍历习题      */
// 习题一：已知中序和前序(或后序) 求 后序(或前序）
//已知 前序遍历和中序遍历序列 求 后序遍历序列       注：用数组实现更好
typedef int DataType;
DataType pre[6] = {1,2,3,4,5,6};
DataType in[6] = {3,2,4,1,6,5};
DataType post[6] = {0};
void PreIn_Post(int preL,int inL,int postL,int N){
    if (!N) return;
    if (N==1) {post[postL]=pre[preL];return;} //这一行可有可无
    DataType root=pre[preL];
    post[postL+N-1]=root;
    int i,L,R;              // L是左半部分的大小  R是右半部分的大小
//    for ( i=0; i<N && in[i]!=root; i++);
    for (i=0; i<N; i++) {
        if (in[inL+i]==root)
            break;
    }
    L=i;R=N-1-L;
    PreIn_Post(preL+1, inL, postL, L);         //对左半部分进行递归
    PreIn_Post(preL+L+1, inL+L+1, postL+L, R); //对右半部分进行递归
}
//int main(){
//    PreIn_Post(0, 0, 0, 6);
//    for (int i=0;i<6;i++)
//        printf("%d\t",post[i]);
//    return 0;
//}


////已知 后序遍历和中序遍历序列 求 前序遍历序列       注：用数组实现更好
//typedef int DataType;
//DataType post[6]={3,4,2,6,5,1};
//DataType in[6]={3,2,4,1,6,5};
//DataType pre[6]={0};
//void PostIn_Pre(int postR,int inL,int preL,int N){
//    if (!N) return;
////    if (N==1) {pre[preL]=post[postR];return;}   //这一行可有可无
//    DataType root=post[postR];
//    pre[preL]=root;
//    int i,L,R;
//    for (i=0;i<N && in[inL+i]!=root;i++);
//    //注1：in[inL+i]!=root 别忘记inL了
//    //注2：不能直接初始化i=inL，这会影响L和R大小的计算 --> 事实上PostL，inL，preL任是在原来数组范畴内，但是L和R可以认为是新的数组
//    L=i;R=N-1-L;
//    PostIn_Pre(postR-R-1, inL, preL+1, L); //注postR-L不正确
//    PostIn_Pre(postR-1, inL+L+1, preL+L+1, R);
//}
//
//int main(){
//    PostIn_Pre(5, 0, 0, 6);
//    for (int i=0;i<6;i++)
//        printf("%d\t",pre[i]);
//    return 0;
//}

// 习题二： 将一已知序列 构建 完全二叉搜索树

#include <math.h>
int arr[10]={9,8,7,6,5,4,3,2,1};
int T[10]={0};
void SelectionSort(int arr[],int num){
    int i,j,tmp,k;
    for (i=0; i<num-1; i++) {
        k=i;
        for (j=i+1; j<num; j++) {
            if (arr[j]<arr[i])
                k=j;
        }
        tmp=arr[k];arr[k]=arr[i];arr[i]=tmp;
    }
}
int Min(int a,int b){
    return (a<b? a:b);
}
int GetLeftLength(int N){
    int H,X;
    H=log(N+1)/log(2);
    X=N-pow(2, H)+1;
    return (pow(2, H-1)-1+Min(X, pow(2, H-1)));
}

void CreataCompleteBinarySearchTree(int left,int right,int root){
    int n=right-left+1;
    if (!n) return;
    int L=GetLeftLength(n);
    T[root]=arr[left+L];
    int leftroot,rightroot;
    leftroot=root*2+1;
    rightroot=leftroot+1;
    CreataCompleteBinarySearchTree(left, left+L-1, leftroot);
    CreataCompleteBinarySearchTree(left+L+1, right, rightroot);
}

//int main(){
//    SelectionSort(arr, 10);
//    CreataCompleteBinarySearchTree(0, 9, 0);
//    for (int i=0;i<10;i++) printf("%d\t",T[i]);
//    return 0;
//}

// 习题三：判断学生哈夫曼编码是否正确

// 1.计算最有编码长度即 WPL
typedef int WeightType;
typedef struct HNode *Heap;
struct HNode{
    WeightType *data;
    int size;
    int capacity;
};
typedef Heap MinHeap;
#define MINDATA -1
MinHeap CreateMinHeap(int maxsize){
    MinHeap H=(MinHeap)malloc(sizeof(MinHeap));
    H->data=(int*)malloc((maxsize+1)*sizeof(int));
    H->capacity=maxsize;
    H->size=0;
    H->data[0]=MINDATA;  //哨兵
    return H;
}
bool Isfull(MinHeap H){
    return (H->size==H->capacity);
}
bool Isempty(MinHeap H){
    return (H->size==0);
}
void insert(MinHeap H,int X){ //本题中返回 void 也行
    if (Isfull(H)) {
        printf("Heap is full");
        return;
    }
    int i;
    i=++H->size;
    for (; H->data[i/2]>X; i/=2)
        H->data[i]=H->data[i/2];
    H->data[i]=X;
}

WeightType deletemin(MinHeap H){
    int Parent,Child;
    WeightType MinItem,X;
    if (Isempty(H)) {
        printf("MinHeap is empty");
        return -1;
    }
    MinItem=H->data[1];
    X=H->data[H->size--];
    for (Parent=1; Parent*2<=H->size; Parent=Child) { // <=?
        Child=Parent*2;
        if ((Child!=H->size)&&(H->data[Child]>H->data[Child+1]))
            Child++;
        if (X<=H->data[Child]) break;
        else H->data[Parent]=H->data[Child];
    }
    H->data[Parent]=X;
    return MinItem;
}

typedef struct hnode *HuffmanTree;
struct hnode{
    WeightType weight;
    HuffmanTree left;
    HuffmanTree right;
};

HuffmanTree Huffman(MinHeap H){
    //将数组形式的树转化为链表形式的树  注：数组形式的树认为是完全二叉树
    HuffmanTree T=NULL;
    HuffmanTree t,new,tmp;
    int cnt=H->size;
    T=(HuffmanTree)malloc(sizeof(HuffmanTree));
    t=(HuffmanTree)malloc(sizeof(HuffmanTree));
    new=(HuffmanTree)malloc(sizeof(HuffmanTree));
    t->weight=deletemin(H);t->left=t->right=NULL;
    new->weight=deletemin(H);new->left=new->right=NULL;
    T->left=t;
    T->right=new;
    T->weight=t->weight+new->weight;
    cnt-=2;
    while (cnt) {
        tmp=T;
        T=(HuffmanTree)malloc(sizeof(HuffmanTree));
        new=(HuffmanTree)malloc(sizeof(HuffmanTree));
        new->weight=deletemin(H);new->left=new->right=NULL;cnt-=1;
        T->left=tmp;
        T->right=new;
        T->weight=tmp->weight+new->weight;
        printf("t1=%d t2=%d %d\n",tmp->weight,new->weight,T->weight);
    }
    return T;
}

int WPL(HuffmanTree T, int Depth){
    if (!T->left && !T->right)
        return (Depth*T->weight);
    else
        return (WPL(T->left, Depth+1)+WPL(T->right, Depth+1));
}
void pretraversal(HuffmanTree T){
    if(T){
        printf("%d\t",T->weight);
        pretraversal(T->left);
        pretraversal(T->right);
    }
}

int main(){
    WeightType f[4]={1,3,4,2};
    MinHeap H=CreateMinHeap(100);
    for (int i=0; i<4; i++)
        insert(H, f[i]);
//    for (int i=0; i<4; i++) {
//        printf("%d\t",deletemin(H));
//    }
    HuffmanTree T=Huffman(H);
    pretraversal(T);
    int Min_wpl=WPL(T, 0);
    printf("%d\n",Min_wpl);
    printf("%d\n",T->left->weight);
    return 0;
}
