#include "heap.h"
#include <time.h>

//建小堆
//TopK问题，在n个数中，找出最大的k个数

// void HeapSort(int *a,int n)
// {
//     //建小堆
//     for(int i=(n-1-1)/2;i>=0;i--) //n-1是最后一个节点位置，再-1除2是最后一个节点的父亲
//     {
//         AdjustDown(a,n,i);
//     }

//     //建从大到小的有序数组
//     int j=1;
//     while(j<n)
//     {
//         swap(&a[0],&a[n-j]);
//         AdjustDown(a,n-j,0);
//         j++;
//     }
// }

void CreateDataFile(const char *filename,int N)
{
    FILE *fin=fopen(filename,"w");
    if(!fin)
    {
        perror("fopen is fail\n");
        return ;
    }
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        fprintf(fin,"%d\n",rand()%1000000); //向文件中写入N个随机数
    }
    fclose(fin);
}

void PrintTopK(const char *filename,int k)
{
    FILE *fout=fopen(filename,"r");
    if(!fout)
    {
        perror("fopen is fail\n");
        return ;
    }

    int* minHeap=(int *)malloc(sizeof(int)*k);
    //从文件中取出k个数
    for(int i=0;i<k;i++)
    {
        fscanf(fout,"%d",&minHeap[i]);
    }
    //建立小堆
    for(int i=(k-1-1)/2;i>=0;i--)
    {
        AdjustDown(minHeap,k,i);
    }
    //将文件中的数与小堆比较，比堆顶大的数替换堆顶，再向下调整，重复这个工程，就可以找到最大的k个数
    int val=0;
    while(fscanf(fout,"%d",&val)!=EOF)
    {
        if(val>minHeap[0])
        {
            minHeap[0]=val;
            AdjustDown(minHeap,k,0);
        }
    }
    //排序，从大到小
    int j=1;
    while(j<k)
    {
        swap(&minHeap[0],&minHeap[k-j]);
        AdjustDown(minHeap,k-j,0);
        j++;
    }

    for(int i=0;i<k;i++)
    {
        printf("%d ",minHeap[i]);
    }
    printf("\n");

    free(minHeap);
    fclose(fout);

}
int main()
{

    int k=10;
    int N=10000;
    const char *filename="randnumber";
    CreateDataFile(filename,N);
    PrintTopK(filename,k);

    return 0;
}