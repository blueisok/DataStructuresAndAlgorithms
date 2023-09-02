#include "slist.h"
void SListPrint(SLNode*phead)
{
    SLNode *src=phead;
    while(src!=NULL)
    {
        printf("%d->",src->data);
        src=src->next;
    }
    printf("NULL\n");

}

SLNode * BuySList(SLDataType x)
{
    SLNode *newnode=(SLNode *)malloc(sizeof(SLNode));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void SListPushBack(SLNode**phead,SLDataType x)
{
    SLNode*newnode=BuySList(x);

    if(*phead==NULL) //一开始无节点
    {
        *phead=newnode;
    }
    else
    {
        SLNode*tail=*phead;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=newnode;

    }
}

void SListPushFront(SLNode**phead,SLDataType x)
{
    SLNode *newnode=BuySList(x);
    newnode->next=*phead;
    *phead=newnode;

}

void SListPopBack(SLNode**phead)
{

    if(*phead==NULL) //无节点
    {
        return;
    }
    else if((*phead)->next==NULL)//只有一个节点
    {
        free(*phead);
        *phead=NULL;
    }
    else
    {
        SLNode *tail=*phead;
        SLNode *front=NULL;
        while (tail->next!=NULL)
        {
            front=tail;
            tail=tail->next;
        }
        free(tail);
        front->next=NULL;
    }

    

}
void SListPopFront(SLNode**phead)
{
    SLNode *temp=(*phead)->next;
    free(*phead);
    *phead=temp;

}

//查找data相等的结点，返回节点
SLNode* SListFind(SLNode *phead,SLDataType x)
{
    SLNode *cur=phead;
    while(cur)
    {
        if(cur->data!=x)
        {
            cur=cur->next;
        }
        else
        {
            return cur;
        }
    }
    return NULL;
}

//在pos节点前插入值为x的节点
void SListInsert(SLNode**phead,SLNode *pos,SLDataType x)
{
    SLNode *newnode=BuySList(x);
    if(*phead==pos) //查找节点是第一个节点
    {
        SListPushFront(phead,x);
    }
    else
    {
        SLNode *pre=*phead;
        while(pre->next!=pos)
        {
            pre=pre->next;
        }
        pre->next=newnode;
        newnode->next=pos;
    }

    
}

//删除pos 节点
void SListErase(SLNode **phead,SLNode *pos)
{
    
    if(*phead==pos)
    {
        SListPopFront(phead);
    }
    else
    {
        SLNode*pre=*phead;
        while(pre->next!=pos)
        {
            pre=pre->next;
        }
        pre->next=pos->next;
        free(pos);
    }

}
