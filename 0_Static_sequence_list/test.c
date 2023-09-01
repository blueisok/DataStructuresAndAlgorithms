#include"seqlist.h"

void SeqListTest()
{
    SL s;
    int result;
    SeqListInit(&s);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushBack(&s,4);
    SeqListPushHead(&s,5);
    SeqListPopBack(&s,1);
    SeqListPopHead(&s,1);
 //   SeqListModifi(&s);
    SeqListInsert(&s,2,6);
    result=SeqListFind(&s,3);
    printf("%d\n",result);
    SeqListDestroy(&s);
    SeqListPrint(&s);

}
int main()
{
    SeqListTest();
    return 0;
}