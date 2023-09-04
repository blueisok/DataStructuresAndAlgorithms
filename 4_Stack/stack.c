#include "stack.h"

void StackInit(st *ps)
{
    assert(ps);
    STDataType*temp=(STDataType*)malloc(2*sizeof(STDataType));
    if(temp==NULL)
    {
        printf("malloc is fail\n");
        exit(-1);
    }
    else
    {
        ps->a=temp;
        ps->capacity=2;
        ps->top=0;
    }

}
void StackDestroy(st*ps)
{
    assert(ps);
    free(ps->a);
    ps->capacity=ps->top=0;
}

void StackPush(st*ps,STDataType x)
{
    assert(ps);

    //判断是否扩容
    if(ps->top==ps->capacity)
    {
        STDataType* temp=(STDataType *)realloc(ps->a,2*ps->capacity*sizeof(STDataType));
        if(temp==NULL)
        {
            printf("realloc is fail\n");
            exit(-1);
        }
        else
        {
            ps->a=temp;
            ps->capacity*=2;
        }
    }

    ps->a[ps->top]=x;
    ps->top++;
}

void StackPop(st*ps)
{
    assert(ps);
    assert(ps->top>0);
    ps->top--;
}

STDataType StackTop(st*ps)//返回栈顶元素
{
    assert(ps);
    return ps->a[ps->top-1];
}

bool StackIsNull(st*ps)//栈是否为空
{
    assert(ps);

    return ps->top==0;
}

int StackSize(st*ps)
{
    return ps->top;
}
