#include "queue.h"

void QueueInit(queue *pq)
{
    assert(pq);
    pq->head=pq->tail=NULL;

}

void QueueDestroy(queue*pq)
{
    assert(pq);
    qnode *cur=pq->head;
    while(cur)
    {
        qnode *next=cur->next;
        free(cur);
        cur=next;
    }
}

void QueuePush(queue*pq,QDatatype x)
{
    assert(pq);
    qnode *newnode=(qnode*)malloc(sizeof(qnode));
    newnode->data=x;
    newnode->next=NULL;
    if(newnode==NULL)
    {
        printf("malloc is fail\n");
        exit(-1);
    }
    //只有一个节点
    if(pq->tail==NULL)
    {
        pq->head=pq->tail=newnode;
    }
    else
    {
        pq->tail->next=newnode;
        pq->tail=newnode;
    }
    
}

void QueuePop(queue*pq)
{
    assert(pq);
    assert(pq->head);

    //只剩一个节点
    if(pq->head->next==NULL)
    {
        free(pq->head);
        pq->head=pq->tail=NULL;
    }
    else
    {
        qnode *next=pq->head->next;
        free(pq->head);
        pq->head=next;
    }

}

//返回头节点
QDatatype QueueFront(queue*pq)
{
    assert(pq);
    assert(pq->head);
    return pq->head->data;
}

//返回尾节点
QDatatype QueueBack(queue*pq)
 {
    assert(pq);
    assert(pq->tail);
    return pq->tail->data;
 }

int QueueSize(queue*pq)
{
    assert(pq);
    int size=0;
    qnode *cur=pq->head;
    while(cur)
    {
        size++;
        cur=cur->next;
    }
    return size;
}

bool QueueEmpty(queue *pq)
{
    return pq->head==NULL;
}


