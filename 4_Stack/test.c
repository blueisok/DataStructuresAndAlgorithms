#include "stack.h"


void menu()
{
    printf("*****************\n");
    printf("***1�����ݽ�ջ****\n");
    printf("****2�����ݳ�ջ***\n");
    printf("***3����ӡջ��****\n");
    printf("*4����ӡջ���ݸ���*\n");
    printf("**5����ӡջ������**\n");
    printf("******6���˳�*****\n");
    printf("*****************\n");

}

// void test()
// {
//     st ps;
//     StackInit(&ps);
//     StackPush(&ps,1);
//     StackPush(&ps,2);
//     StackPush(&ps,7);
//     StackPush(&ps,3);
//     printf("%d ",StackTop(&ps));
//     StackPop(&ps);
//     printf("%d ",StackTop(&ps));
//     StackPop(&ps);
//     StackPush(&ps,9);
//     StackPush(&ps,15);
//     StackPush(&ps,6);
//     StackPop(&ps);

//     while(!StackIsNull(&ps))
//     {
//         printf("%d ",StackTop(&ps));
//         StackPop(&ps);
//     }
//     printf("\n");


//     StackDestroy(&ps);

// }

int main()
{
    st ps;
    StackInit(&ps);
    int input=0;
    int putdata=0;
    do
    {
        menu();
        printf("��ѡ��\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            printf("�������ջ����\n");
            scanf("%d",&putdata);
            StackPush(&ps,putdata);
            break;
            case 2:
            StackPop(&ps);
            printf("��ջ���ݳɹ�\n");
            break;
            case 3:
            while(!StackIsNull(&ps))
            {
                printf("%d ",StackTop(&ps));
                StackPop(&ps);
            }
            printf("\n");
            break;
            case 4:
            printf("ջ�Ĵ�С�� %d \n",StackSize(&ps));
            break;
            case 5:
            printf("ջ��Ԫ���� %d \n",StackTop(&ps));
            break;
            case 6:
            printf("�˳��ɹ�\n");
            break;
        }
    } while (input!=6);
    

    // test();
    StackDestroy(&ps);
    return 0;
}