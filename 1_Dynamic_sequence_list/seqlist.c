#include"seqlist.h"

void SeqListInit(SL *ps)
{
    ps->a=NULL;
    ps->size=ps->capacity=0;
}

void SeqListDestroy(SL*ps)
{
    free(ps->a);
    ps->a=NULL;
    ps->size=ps->capacity=0;

}

void SeqListCheckCapacity(SL*ps)
{
    if(ps->size==ps->capacity)
    {
        int newcapacity=ps->capacity==0?4:ps->capacity*2;
        SQDataType*temp=(SQDataType*)realloc(ps->a,sizeof(SQDataType)*newcapacity);
        if(temp==NULL)
        {
            printf("realloc is fail\n");
            exit(-1);
        }
        else
        {
            ps->a=temp;
            ps->capacity=newcapacity;
        }
    }

}

void SeqListInsert(SL*ps,int pos,SQDataType x)
{
    assert(pos<=ps->size);
    SeqListCheckCapacity(ps);
    int end=ps->size-1;
    while(end>=pos)
    {
        ps->a[end+1]=ps->a[end];
        end--;
    }
    ps->a[pos]=x;
    ps->size++;

}

void SeqListPushHead(SL*ps,SQDataType x)
{
    SeqListInsert(ps,0,x);

}

void SeqListPushBack(SL*ps,SQDataType x)
{
    SeqListInsert(ps,ps->size,x);
}

void SeqListPopHead(SL*ps)
{
    for(int temp=0;temp<ps->size-1;temp++)
    {
        ps->a[temp]=ps->a[temp+1];
    }
    ps->a[ps->size-1]=0;
    ps->size--;

}

void SeqListPopBack(SL*ps)
{
    ps->a[ps->size-1]=0;
    ps->size--;
}

void SeqListModity(SL*ps,int pos,SQDataType x)
{
    assert(pos<=ps->size);
    SeqListCheckCapacity(ps);
    ps->a[pos]=x;
    
}

int SeqListFind(SL*ps,SQDataType x)
{
    for(int i=0;i<ps->size;i++)
    {
        if(x==ps->a[i])
        {
            return i+1;
        }
    }
    return -1;
}

void SeqListPrint(SL*ps)
{
    for(int i=0;i<ps->size;i++)
    {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}