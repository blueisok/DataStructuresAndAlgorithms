#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<stdlib.h>
typedef int SLDataType;

typedef struct slist
{
    SLDataType data;
    struct slist *next;
}SLNode;

void SListPushBack(SLNode**phead,SLDataType x);
void SListPrint(SLNode*phead);
void SListPushFront(SLNode**phead,SLDataType x);
void SListPopBack(SLNode**phead);
void SListPopFront(SLNode**phead);
SLNode* SListFind(SLNode *phead,SLDataType x);
SLNode * BuySList(SLDataType x);
void SListInsert(SLNode**phead,SLNode *pos,SLDataType x);
void SListErase(SLNode **phead,SLNode *pos);


#endif