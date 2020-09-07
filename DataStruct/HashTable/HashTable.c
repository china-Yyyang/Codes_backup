#include "HashTable.h"

Index Hash(const ElementType Key,int TableSize){  //取余法
    return Key % TableSize;
}
//Index Hash(const char *Key,int TableSize){
//    unsigned int h=0;
//    while (*Key != '\0')
//        h=(h<<5)+ *Key++;
//    return h % TableSize;
//}

int NextPrime( int N )
{ /* 返回大于N且不超过MAXTABLESIZE的最小素数 */
    int i, p = (N%2)? N+2 : N+1; /*从大于N的下一个奇数开始 */
 
    while( p <= MAXTABLESIZE ) {
        for( i=(int)sqrt(p); i>2; i-- )
            if ( !(p%i) ) break; /* p不是素数 */
        if ( i==2 ) break; /* for正常结束，说明p是素数 */
        else  p += 2; /* 否则试探下一个奇数 */
    }
    return p;
}
 
HashTable CreateTable( int TableSize )
{
    HashTable H;
    int i;
 
    H = (HashTable)malloc(sizeof(struct TblNode));
    /* 保证散列表最大长度是素数 */
    H->TableSize = NextPrime(TableSize);
    /* 声明单元数组 */
    H->Cells = (Cell *)malloc(H->TableSize*sizeof(Cell));
    /* 初始化单元状态为“空单元” */
    for( i=0; i<H->TableSize; i++ )
        H->Cells[i].Info = Empty;
 
    return H;
}


Position Find( HashTable H, ElementType Key )
{
    Position CurrentPos, NewPos;
    int CNum = 0; /* 记录冲突次数 */
 
    NewPos = CurrentPos = Hash( Key, H->TableSize ); /* 初始散列位置 */
    /* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
    while( H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key ) {
                                           /* 字符串类型的关键词需要 strcmp 函数!! */
        /* 统计1次冲突，并判断奇偶次 */
        if( ++CNum%2 ){ /* 奇数次冲突 */
            NewPos = CurrentPos + (CNum+1)*(CNum+1)/4; /* 增量为+[(CNum+1)/2]^2 */
            if ( NewPos >= H->TableSize )
                NewPos = NewPos % H->TableSize; /* 调整为合法地址 */
        }
        else { /* 偶数次冲突 */
            NewPos = CurrentPos - CNum*CNum/4; /* 增量为-(CNum/2)^2 */
            while( NewPos < 0 )
                NewPos += H->TableSize; /* 调整为合法地址 */
        }
    }
    return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}
 
bool Insert( HashTable H, ElementType Key )
{
    Position Pos = Find( H, Key ); /* 先检查Key是否已经存在 */
 
    if( H->Cells[Pos].Info != Legitimate ) { /* 如果这个单元没有被占，说明Key可以插入在此 */
        H->Cells[Pos].Info = Legitimate;
        H->Cells[Pos].Data = Key;
        /*字符串类型的关键词需要 strcpy 函数!! */
        return true;
    }
    else {
        printf("键值已存在");
        return false;
    }
}


 
//HashTable CreateTable( int TableSize )
//{
//    HashTable H;
//    int i;
//
//    H = (HashTable)malloc(sizeof(struct TblNode));
//    /* 保证散列表最大长度是素数，具体见代码5.3 */
//    H->TableSize = NextPrime(TableSize);
//
//    /* 以下分配链表头结点数组 */
//    H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
//    /* 初始化表头结点 */
//    for( i=0; i<H->TableSize; i++ ) {
//         H->Heads[i].Data[0] = '\0';
//         H->Heads[i].Next = NULL;
//    }
//
//    return H;
//}
//
//Position Find( HashTable H, ElementType Key )
//{
//    Position P;
//    Index Pos;
//
//    Pos = Hash( Key, H->TableSize ); /* 初始散列位置 */
//    P = H->Heads[Pos].Next; /* 从该链表的第1个结点开始 */
//    /* 当未到表尾，并且Key未找到时 */
//    while( P && strcmp(P->Data, Key) )
//        P = P->Next;
//
//    return P; /* 此时P或者指向找到的结点，或者为NULL */
//}
//
//bool Insert( HashTable H, ElementType Key )
//{
//    Position P, NewCell;
//    Index Pos;
//
//    P = Find( H, Key );
//    if ( !P ) { /* 关键词未找到，可以插入 */
//        NewCell = (Position)malloc(sizeof(struct LNode));
//        strcpy(NewCell->Data, Key);
//        Pos = Hash( Key, H->TableSize ); /* 初始散列位置 */
//        /* 将NewCell插入为H->Heads[Pos]链表的第1个结点 */
//        NewCell->Next = H->Heads[Pos].Next;
//        H->Heads[Pos].Next = NewCell;
//        return true;
//    }
//    else { /* 关键词已存在 */
//        printf("键值已存在");
//        return false;
//    }
//}
//
//void DestroyTable( HashTable H )
//{
//    int i;
//    Position P, Tmp;
//
//    /* 释放每个链表的结点 */
//    for( i=0; i<H->TableSize; i++ ) {
//        P = H->Heads[i].Next;
//        while( P ) {
//            Tmp = P->Next;
//            free( P );
//            P = Tmp;
//        }
//    }
//    free( H->Heads ); /* 释放头结点数组 */
//    free( H );        /* 释放散列表结点 */
//}
