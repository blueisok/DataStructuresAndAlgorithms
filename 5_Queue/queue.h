#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDatatype;

typedef struct QueueNode
{
    struct QueueNode*next;
    QDatatype data;
    
}qnode;

typedef struct Queue
{
    qnode *head;
    qnode *tail;
}queue;


void QueueInit(queue *pq);
void QueueDestroy(queue*pq);
void QueuePush(queue*pq,QDatatype x);
void QueuePop(queue*pq);
QDatatype QueueFront(queue*pq);
QDatatype QueueBack(queue*pq);
int QueueSize(queue*pq);
bool QueueEmpty(queue *pq);
