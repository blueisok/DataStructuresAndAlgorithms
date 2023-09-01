
#include"seqlist.h"

void SeqListInit(SL*PS)
{
    memset(PS->data,0,sizeof(SL)*DATA_MAX);
    PS->size=0;
}

//尾插法
void SeqListPushBack(SL*PS,SQDataType x)
{
    if(PS->size>=DATA_MAX)
    {
        printf("seqlist is full \n");
        return ;

    }

    PS->data[PS->size]=x;
    PS->size++;

}
//头插法
void SeqListPushHead(SL*PS,SQDataType x)
{
    int temp=PS->size;
    if(PS->size>=DATA_MAX)
    {
        printf("seqlist is full \n");
        return ;

    }
    for(;temp>0;temp--)
    {
        PS->data[temp]=PS->data[temp-1];
    }
    PS->data[temp]=x;
    PS->size++;



}
//尾删法(num删除个数)
void SeqListPopBack(SL*PS,int num)
{
    assert(PS->size>0);
    for(;num>0;num--)
    {
        PS->data[PS->size-1]=0;
        PS->size--;
    }


}

//头删法(num删除个数)
void SeqListPopHead(SL*PS,int num)
{
    int temp=0;
    assert(PS->size>0);
    for(;num>0;num--)
    {
        for(temp=0;temp<PS->size-1;temp++)
        PS->data[temp]=PS->data[temp+1];
        PS->data[PS->size-1]=0;
        PS->size--;
    }


}

//修改顺序表
void SeqListModifi(SL*PS)
{
    int pos,num;
    printf("please input modificatiom position\n");
    scanf("%d",&pos);
    while(pos<=0||pos>PS->size)
    {
        printf("input is error\n");
        printf("please input modificatiom position again\n");
        scanf("%d",&pos);
    }
    printf("please input modification num\n");
    scanf("%d",&num);
    PS->data[pos-1]=num;

}

//打印顺序表
void SeqListPrint(SL*PS)
{
    int i=0;
    for(i=0;i<PS->size;i++)
    printf("%d ",PS->data[i]);
    printf("\n");

}

int SeqListFind(SL*PS,int num)
{
    for(int i=0;i<PS->size;i++)
    {
        if(num==PS->data[i])
        return i+1;
    }
}

void SeqListInsert(SL*PS,int pos,int num)
{
    assert(pos<=PS->size);
    int end=PS->size;
    while(pos<=end) //移位
    {
        PS->data[end+1]=PS->data[end];
        end--;
    }
    PS->data[pos-1]=num;
    PS->size++;
}

void SeqListDestroy(SL*PS)
{
    for(int i=0;i<PS->size;i++)
    {
        PS->data[i]=0;
    }
    PS->size=0;
}

