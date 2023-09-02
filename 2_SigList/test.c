#include"slist.h"

void test1()
{
    SLNode *plist=NULL;
    SListPushBack(&plist,1);
    SListPushBack(&plist,2);
    SListPushBack(&plist,3);
    SListPushFront(&plist,5);
    SListPushFront(&plist,6);
    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPopFront(&plist);
    SLNode *findnode=SListFind(plist,1);
    if(findnode)
    {
        SListInsert(&plist,findnode,10);
    }
    SLNode *findnode2=SListFind(plist,1);
    if(findnode2)
    {
        SListErase(&plist,findnode2);
    }
    SListPrint(plist);
}

int main()
{
    test1();
    return 0;
}