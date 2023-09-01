#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SQDataType;

typedef struct seqlist
{
    SQDataType *a;
    int size; //当前大小
    int capacity; //容量
}SL;

void SeqListInit(SL *ps);
void SeqListDestroy(SL*ps);
void SeqListCheckCapacity(SL*ps);
void SeqListInsert(SL*ps,int pos,SQDataType x);
void SeqListPushHead(SL*ps,SQDataType x);
void SeqListPushBack(SL*ps,SQDataType x);
void SeqListPopHead(SL*ps);
void SeqListPopBack(SL*ps);
void SeqListModity(SL*ps,int pos,SQDataType x);
int SeqListFind(SL*ps,SQDataType x);
void SeqListPrint(SL*ps);

#endif