#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 100
typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode* next;
} LnStack;

void Init(SqStack** Stack);
bool Push(SqStack* Stack, ElemType e);
bool Pop(SqStack* Stack, ElemType* e);
bool GetTop(SqStack* Stack, ElemType* e);
// Transmit infix to sufix
bool Transmit(char from[], char to[]);
// Calculate the expression
bool Calculate(char exp[], ElemType* ans);