#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int LDataType;

typedef struct listnode
{
    struct listnode*prev;
    struct listnode*next;
    LDataType data;
}listnode;

listnode * ListInit();
listnode * BuyListNode(LDataType x);
void ListPushBack(listnode *phead,LDataType x);
void ListPushFront(listnode *phead,LDataType x);
void ListPrint(listnode *phead);
void ListPopFront(listnode *phead);
void ListPopBack(listnode*phead);
void ListInsert(listnode *phead,listnode *pos,LDataType x);
void ListErase(listnode *phead,listnode *pos);
listnode* ListFind(listnode *phead,LDataType x);
void ListDtroy(listnode **phead);




#endif