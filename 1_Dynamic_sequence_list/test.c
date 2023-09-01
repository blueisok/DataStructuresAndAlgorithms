#include "seqlist.h"

void test ()
{
    SL s;
    SeqListInit(&s);
    SeqListPushBack(&s,1);
    SeqListPushBack(&s,2);
    SeqListPushBack(&s,3);
    SeqListPushHead(&s,5);
    SeqListPushHead(&s,6);
    SeqListInsert(&s,1,3);
    SeqListModity(&s,0,7);
    SeqListPopHead(&s);
    SeqListPopBack(&s);
    SeqListPrint(&s);


}

int main()
{
    
    test ();
    return 0;
}