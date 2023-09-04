#include "stack.h"


void menu()
{
    printf("*****************\n");
    printf("***1、数据进栈****\n");
    printf("****2、数据出栈***\n");
    printf("***3、打印栈表****\n");
    printf("*4、打印栈数据个数*\n");
    printf("**5、打印栈顶数据**\n");
    printf("******6、退出*****\n");
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
        printf("请选择\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            printf("请输入进栈数据\n");
            scanf("%d",&putdata);
            StackPush(&ps,putdata);
            break;
            case 2:
            StackPop(&ps);
            printf("出栈数据成功\n");
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
            printf("栈的大小是 %d \n",StackSize(&ps));
            break;
            case 5:
            printf("栈顶元素是 %d \n",StackTop(&ps));
            break;
            case 6:
            printf("退出成功\n");
            break;
        }
    } while (input!=6);
    

    // test();
    StackDestroy(&ps);
    return 0;
}