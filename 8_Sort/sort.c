#include"sort.h"
#include"stack.h"

void Swap(int*p1,int*p2)
{
    int tmp=*p1;
    *p1=*p2;
    *p2=tmp;
}


void InsertSort(int*a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int end=i;
        int tmp=a[end+1];
        while(end>=0)
        {
            if(tmp<a[end])
            {
                a[end+1]=a[end];
                end--;
            }
            else 
            {
                break;
            }
        }
        a[end+1]=tmp;
    }
}

void ShellSort(int* a,int n)
{

    
    int grap=n;
    while(grap>1)
    {
      grap=grap/3+1;  
     for(int i=0;i<(n-grap);i++)
     {
        int end=i;
        int tmp=a[end+grap];
        while(end>=0)
        {
            if(tmp<a[end])
            {
                a[end+grap]=a[end];
                end-=grap;
            }
            else 
            {
                break;
            }
        }
        a[end+grap]=tmp;
      }
    }
}

void AdjustDown(int* a,int n,int parent)//向下调整
{
    int chlid=parent*2+1;
    while(chlid<n)
    {
      if(chlid+1<n&&a[chlid]<a[chlid+1])
      {
         chlid++;
      }

      if(a[parent]<a[chlid])
      {
          Swap(&a[parent],&a[chlid]);
          parent=chlid;
          chlid=parent*2+1;
      }
      else 
      {
          break;
      }

      
    }
}

void HeapSort(int* a,int n)
{
    for(int i=(n-1-1)/2;i>=0;i--)//建堆
    {
        AdjustDown(a,n,i);
    }

    //选数
    int i=1;
    while(i<n)
    {
        Swap(&a[0],&a[n-i]);
        AdjustDown(a,n-i,0);
        i++;
    }
}

void SelectSort(int* a,int n)
{
    int begin=0;
    int end=n-1;
    while(begin<end)
    {

      int mini=begin;
      int maxi=begin;
      for(int i=begin+1;i<=end;i++)
      {
          if(a[i]>a[maxi])
          {
              maxi=i;
          }
          if(a[i]<a[mini])
          {
              mini=i;
          }

      }
      Swap(&a[begin],&a[mini]);
      if(begin==maxi)// 特殊情况，当bigin和maxi重合，要修正maxi的值
      {
          maxi=mini;
      }
      Swap(&a[end],&a[maxi]);
      begin++;
      end--;
    }

}

void BubbleSort(int* a,int n) //冒泡排序
{
    for(int i=0;i<n-1;i++) //控制排序的趟数
    {
        int exchange=0;
        for(int j=1;j<n-i;j++)//一趟排序
        {
            if(a[j-1]>a[j])
            {
                Swap(&a[j-1],&a[j]);
                exchange=1;
            }
        }
        if(exchange==0)
        {
            break;
        }
    }
}

int GetMidIndex(int* a,int left,int right)//三数取中间值
{
    int mid=(left+(right-left))/2;
    if(a[left]>a[mid])
    {
        if(a[mid]>a[right])
            return mid;
        else if(a[left]>a[right])
            return right;
        else 
            return left;
    }
    else //a[left]<=a[mid] 
    {
        if(a[mid]<a[right])
            return mid;
        else if(a[left]>a[right])
            return left;
        else 
            return right;
    }
}

//快速排序3种变形
int  PastSort1(int* a,int left,int right) //hoare 版本
{

    int mid=GetMidIndex(a,left,right);
    Swap(&a[mid],&a[right]);
    int key=right;
    while(left<right)
    {
        while(left<right&&a[left]<=a[key])//右边作key，左边先走，找大于key的值停下
        {
            left++;
        }
        while(left<right&&a[right]>=a[key])//右边走，找小于key的值停下
        {
            right--;
        }
        if(left<right)
        Swap(&a[left],&a[right]);
    }
    Swap(&a[left],&a[key]);//left和right都可

    return left;
}

int PastSort2(int* a,int left,int right) //挖坑法
{
   // int mid=GetMidIndex(a,left,right);
   // Swap(&a[mid],&a[right]);
    int key=a[right];
    int hole=right;
    while(left<right)
    {
       while(left<right&&a[left]<=key) //找到比key大的值
       {
           left++;
       }
         a[hole]=a[left];
         hole=left;
       while(left<right&&a[right]>=key)
       {
           right--;
       }
       a[hole]=a[right];
       hole=right;
          
     }
    a[hole]=key;
    return hole;
}

int PastSort3(int* a,int left,int right) //前后指针法
{
    int mid=GetMidIndex(a,left,right);
    Swap(&a[mid],&a[right]);
    int  keyi=right;
    int  cur=left;
    int  prev=left-1;
    while(cur<right)
    {
        if(a[cur]<a[keyi]&&++prev!=cur)
        {
            Swap(&a[prev],&a[cur]);
        }
        ++cur;
    }
    Swap(&a[++prev],&a[keyi]);
    return prev; 
}

void QuickSort(int* a,int left,int right)
{
    if(left>=right)
        return ;


    int dev=PastSort1(a,left,right);

     QuickSort(a,left,dev-1);
     QuickSort(a,dev+1,right);
}
void QuickSort1(int* a,int left,int right)
{
    if(left>=right)
        return ;


    int dev=PastSort3(a,left,right);

     QuickSort(a,left,dev-1);
     QuickSort(a,dev+1,right);
}

void QuickSortNoR(int* a,int begin,int end) //快排非递归
{
    st stack;
    StackInit(&stack);
    StackPush(&stack,begin);
    StackPush(&stack,end);
    while(!StackIsNull(&stack))
    {
        int right=StackTop(&stack);
        StackPop(&stack);
        int left=StackTop(&stack);
        StackPop(&stack);

        int dev=PastSort1(a,left,right);
        //[left,dev-1] dev [dev+1,right]

        if(dev+1<right)
        {
            StackPush(&stack,dev+1);
            StackPush(&stack,right);
        }

        if(left<dev-1)
        {
            StackPush(&stack,left);
            StackPush(&stack,dev-1);
        }

    }

    StackDestroy(&stack);
}

void _MergeSort(int* a,int left,int right,int* temp)
{
    if(left>=right)
        return;

    int mid=(left+right)/2;
    //[left,mid] [mid+1,right]
    _MergeSort(a,left,mid,temp);
    _MergeSort(a,mid+1,right,temp);

    //递归返回归并排序
    int begin1=left,end1=mid;
    int begin2=mid+1,end2=right;
    int index=left;
    while(begin1<=end1&&begin2<=end2)
    {
        if(a[begin1]<a[begin2])
            temp[index++]=a[begin1++];
        else
            temp[index++]=a[begin2++];
    }
    
    while(begin1<=end1)
        temp[index++]=a[begin1++];
    while(begin2<=end2)
        temp[index++]=a[begin2++];

    //将temp数组的值重新覆盖a数组值
    for(int i=left;i<=right;i++)
    {
        a[i]=temp[i];
    }
}

void MergeSort(int* a, int n) //归并排序
{
    int* temp=(int*)malloc(sizeof(int)*n);
    _MergeSort(a,0,n-1,temp);

    free(temp);
}

void MergeSortNonR(int* a,int n) //归并排序非递归
{
    int* temp=(int*)malloc(sizeof(int)*n);
    int gap=1;

    while(gap<n){
        for(int j=0;j<n;j+=2*gap){
            int begin1=j,end1=j+gap-1;   //end1 等于左边的位置j加上间距gap-1
            int begin2=j+gap,end2=j+gap*2-1; //end2 等于左边位置j加上两倍的间距-1
            int index=j;

            int copyi=begin1,copyj=end2;

            if(begin2>=n)
                break;
            if(end2>=n)
                end2=n-1;

            while(begin1<=end1&&begin2<=end2){
                if(a[begin1]<a[begin2]){
                    temp[index++]=a[begin1++];
                }
                else{
                    temp[index++]=a[begin2++];
                }
            }

            //处理一组中剩下的值
            while(begin1<=end1){
                temp[index++]=a[begin1++];
            }
            while(begin2<=end2){
                temp[index++]=a[begin2++];
            }

             //将值拷贝回去

            memcpy(a+j, temp+j, (end2-j+1)*sizeof(int));

        }
        gap*=2;
    }
    free(temp);
    temp=NULL;
}


