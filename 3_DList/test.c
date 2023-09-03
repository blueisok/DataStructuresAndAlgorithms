#include "list.h"

void test()
{
    listnode *plist=ListInit();
    ListPushBack(plist,1);
    ListPushBack(plist,2);
    ListPushBack(plist,3);
    ListPushBack(plist,5);
    ListPushFront(plist,6);
    ListPushFront(plist,9);
    ListPrint(plist);
    ListPopBack(plist);
    ListPopFront(plist);
    ListPrint(plist);
    listnode *findnode=ListFind(plist,6);
    if(findnode)
    {
        ListErase(plist,findnode);
    }

    listnode *findnode1=ListFind(plist,2);
    if(findnode1)
    {
        ListInsert(plist,findnode1,10);
    }
    ListPrint(plist);
    ListDtroy(&plist);
    ListPrint(plist);
}

int main()
{
    test();
    return 0;

}