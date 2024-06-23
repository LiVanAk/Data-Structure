#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 1000
typedef char ElemType;

typedef struct 
{  
    ElemType data[MaxSize];
    int length;
} SqList;    	//顺序表类型  

void CreateList(SqList *L, ElemType a[], int n);
void InitList(SqList *L);
void DestroyList(SqList *L);
bool  ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L, int i, ElemType *e);
int LocateElem(SqList *L, ElemType e);

int main(){
    return 0;
}

// 整体建立顺序表
void CreateList(SqList *L, ElemType a[], int n){  
    int i=0,k=0;
    L=(SqList *)malloc(sizeof(SqList));
    while (i<n)		// i扫描a中元素
    {  
        L->data[k]=a[i];
        k++; i++;	// k记录插入到L中的元素个数
    }
    L->length=k;
}

// 初始化线性表
void InitList(SqList *L)
{
    // 分配存放线性表的顺序表空间
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

// 销毁线性表
void DestroyList(SqList *L)
{
    free(L);
}   

// 判定是否为空表
bool  ListEmpty(SqList *L)
{
    return(L->length == 0);
}

// 求线性表的长度
int ListLength(SqList *L)
{
    return(L->length);
}

// 输出线性表
void DispList(SqList *L)
{  
    int i;
    if (ListEmpty(L))
        return;
    for (i=0; i < L->length; i++)
        printf("%c", L->data[i]);
    printf("\n");
} 

// 求某个数据元素值
bool GetElem(SqList *L, int i, ElemType *e)
{     
    if (i<1 || i>L->length)
        return false;
    *e = L->data[i-1];
    return true;
}

// 按元素值查找
int LocateElem(SqList *L, ElemType e)
{  
    int i = 0;
    while (i < L->length && L->data[i] != e)  
        i++;
    if (i >= L->length)
        return 0;
    else
        return i+1;
}

// 插入数据元素
bool ListInsert(SqList *L, int i, ElemType e)
{
    int j;
    if (i<1 || i>L->length+1)
        return false;                   // 参数错误时返回false
    i--;                                // 将顺序表逻辑序号转化为物理序号
    for (j = L->length; j > i; j--)     // 将data[i..n]元素后移一个位置
	    L->data[j] = L->data[j-1];
    L->data[i] = e;                     // 插入元素e
    L->length++;                        // 顺序表长度增1
    return true;                        // 成功插入返回true
}
