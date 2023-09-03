#include "list.h"

listnode * BuyListNode(LDataType x)
{
    listnode *newnode=(listnode*)malloc(sizeof(listnode));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;

}

listnode * ListInit()
{
    listnode *phead=BuyListNode(0);
    phead->next=phead;
    phead->prev=phead;
    return phead;

}

void ListPushBack(listnode *phead,LDataType x)
{
    listnode *newnode=BuyListNode(x);
    (phead->prev)->next=newnode;
    newnode->prev=phead->prev;
    newnode->next=phead;
    phead->prev=newnode;

}

void ListPrint(listnode *phead)
{
    listnode *cur=phead->next;
    while(cur!=phead)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void ListPushFront(listnode *phead,LDataType x)
{
    listnode*newnode=BuyListNode(x);
    newnode->next=phead->next;
    phead->next->prev=newnode;
    phead->next=newnode;
    newnode->prev=phead;

}

void ListPopFront(listnode *phead)
{
    listnode *prev=phead->next;
    listnode *next=prev->next;
    phead->next=next;
    next->prev=phead;
    free(prev);
    prev=NULL;
}

void ListPopBack(listnode*phead)
{
    listnode *next=phead->prev;
    listnode *prev=next->prev;
    prev->next=phead;
    phead->prev=prev;
    free(next);
    next=NULL;
}

listnode* ListFind(listnode *phead,LDataType x)
{
    listnode*cur=phead->next;
    while(cur!=phead)
    {
        if(cur->data==x)
        {
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}

//在pos前插入一个节点
void ListInsert(listnode *phead,listnode *pos,LDataType x)
{
    listnode *newnode=BuyListNode(x);
    listnode *prev=pos->prev;
    prev->next=newnode;
    newnode->prev=prev;
    newnode->next=pos;
    pos->prev=newnode;

}

//删除pos 节点
void ListErase(listnode *phead,listnode *pos)
{
    listnode *prev=pos->prev;
    listnode *next=pos->next;
    prev->next=next;
    next->prev=prev;
    free(pos);
    pos=NULL;

}

void ListDtroy(listnode **phead)
{
    listnode *cur=(*phead)->next;
    while(cur!=*phead)
    {
        listnode *next=cur->next;
        free(cur);
        cur=next;
    }
    free(phead);
    *phead=NULL;


}