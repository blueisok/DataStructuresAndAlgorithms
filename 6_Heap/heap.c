#include "heap.h"

void swap(HPDataType *p1,HPDataType *p2)
{
    HPDataType temp=*p1;
    *p1=*p2;
    *p2=temp;
}

void AdjustDown(HPDataType *a,int n,int root)
{
    int parent=root;
    int child=parent*2+1;
    while(child<n)
    {
        if(child+1<n&&a[child+1]<a[child]) //找出左右孩子，更小的哪个
        {
            child++;
        }
        if(a[child]<a[parent]) //将小的孩子节点与父节点交换
        {
            swap(&a[child],&a[parent]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }

    }

}


void HeapInit(heap *php)
{
    assert(php);
    php->a=NULL;
    php->size=php->capacity=0;
}

void HeapPrint(heap *php)
{
    assert(php);
    for(int i=0;i<php->size;i++)
    {
        printf("%d ",php->a[i]);
    }
    printf("\n");
}

void HeapDestroy(heap *php)
{
    assert(php);
    free(php);
    php->a=NULL;
    php->size=php->capacity=0;
}

void AdjustUp(HPDataType *a,int child)
{
    int parent=(child-1)/2;
    while(child>0)
    {
        if(a[child]<a[parent])
        {
            swap(&a[child],&a[parent]);
            child=parent;
            parent=(child-1)/2;
        }
        else
        {
            break;
        }
    }
}

void HeapPush(heap *php,HPDataType x)
{
    assert(php);

    //扩容
    if(php->size==php->capacity)
    {
        int newcapacity=php->capacity==0?4:php->capacity*2;
        HPDataType *temp=(HPDataType*)realloc(php->a,sizeof(HPDataType)*newcapacity);
        if(!temp)
        {
            perror("realloc is fail\n");
            exit(-1);
        }
        php->a=temp;
        php->capacity=newcapacity;
    }

    php->a[php->size]=x;
    php->size++;
    AdjustUp(php->a,php->size-1);
}

void HeapPop(heap *php)
{
    assert(php);
    assert(!HeapEmpty(php));

    swap(&php->a[0],&php->a[php->size-1]);
    php->size--;
    AdjustDown(php->a,php->size,0);
}

bool HeapEmpty(heap *php)
{
    assert(php);

    return php->size==0;
}
HPDataType HeapTop(heap *php)
{
    assert(php);
    assert(!HeapEmpty(php));

    return php->a[0]; 
}

int HeapSize(heap *php)
{
    assert(php);
    
    return php->size; 
}