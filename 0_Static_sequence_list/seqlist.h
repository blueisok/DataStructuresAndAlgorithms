#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define DATA_MAX 20
typedef int SQDataType;
typedef struct seqlist
{
    SQDataType data[DATA_MAX];
    int size;
}SL;

void SeqListInit(SL*PS);
void SeqListPushBack(SL*PS,SQDataType x);
void SeqListPrint(SL*PS);
void SeqListPushHead(SL*PS,SQDataType x);
void SeqListPopBack(SL*PS,int num);
void SeqListPopHead(SL*PS,int num);
void SeqListModifi(SL*PS);
int SeqListFind(SL*PS,int num);
void SeqListInsert(SL*PS,int pos,int num);
void SeqListDestroy(SL*PS);

#endif

