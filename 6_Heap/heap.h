#pragma onece
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct heap
{
    HPDataType *a;
    int size;
    int capacity;
}heap;

void swap(HPDataType *p1,HPDataType *p2);
void AdjustDown(HPDataType *a,int n,int root);
void HeapInit(heap *php);
void HeapPrint(heap *php);
void HeapDestroy(heap *php);
void AdjustUp(HPDataType *a,int child);
void HeapPush(heap *php,HPDataType x);
void HeapPop(heap *php);
bool HeapEmpty(heap *php);
HPDataType HeapTop(heap *php);
int HeapSize(heap *php);
