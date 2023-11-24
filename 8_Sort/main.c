#include"sort.h"

void PrintArray(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void TestInsertSort()
{
    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    InsertSort(arr,n);
    PrintArray(arr,n);
}
void TestShellSort()
{
    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    ShellSort(arr,n);
    PrintArray(arr,n);
}

void TestHeapSort()
{

    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    HeapSort(arr,n);
    PrintArray(arr,n);
}

void TestSelectSort()
{
    
    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    SelectSort(arr,n);
    PrintArray(arr,n);
}
void TestBulleSort()
{

    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    BubbleSort(arr,n);
    PrintArray(arr,n);
}

void TestQuickSort()
{

    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    int left=0;
    int right=n-1;
    PrintArray(arr,n);
    QuickSort(arr,left,right);
    PrintArray(arr,n);
}
void TestQuickSort1()
{

    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    int left=0;
    int right=n-1;
    PrintArray(arr,n);
    QuickSort1(arr,left,right);
    PrintArray(arr,n);
}
void TestQuickSortNoR()
{

    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    int left=0;
    int right=n-1;
    PrintArray(arr,n);
    QuickSortNoR(arr,left,right);
    PrintArray(arr,n);
}

void TestMergeSort()
{

    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    MergeSort(arr,n);
    PrintArray(arr,n);
}

void TestMergeSortNonR()
{
    int arr[]={10,7,8,13,6,3,28,16,1,2,3};
    int n=(sizeof(arr)/sizeof(arr[0]));
    PrintArray(arr,n);
    MergeSortNonR(arr,n);
    PrintArray(arr,n);
}

int main()
{
    
  
    // TestInsertSort(); 
    // printf("\n");
    // TestShellSort();
    // printf("\n");
    // TestHeapSort();
    // printf("\n");
    // TestSelectSort();
    // printf("\n");
    // TestBulleSort();
    // printf("\n");
    // printf("-----------------\n");
    // TestQuickSort();
    // printf("\n");
    // TestQuickSort1();
    // printf("\n");
    //TestQuickSortNoR();
    TestMergeSort();
    printf("\n");
    TestMergeSortNonR();
    return 0;
}
