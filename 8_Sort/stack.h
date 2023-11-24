#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct stack
{
    STDataType * a;
    int top;
    int capacity;
}st;

void StackInit(st *ps);
void StackDestroy(st*ps);
void StackPush(st*ps,STDataType x);
void StackPop(st*ps);
STDataType StackTop(st*ps);//返回栈顶元素
bool StackIsNull(st*ps);//栈是否为空
int StackSize(st*ps);