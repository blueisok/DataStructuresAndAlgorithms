#include "queue.h"

void menu()
{
    printf("******************\n");
    printf("******队列******\n");
    printf("***1.插入数据***\n");
    printf("***2.删除数据***\n");
    printf("**3.返回头节点**\n");
    printf("**4.返回尾节点**\n");
    printf("***5.返回长度***\n");
    printf("***6.是否为空***\n");
    printf("***7.打印队列***\n");
    printf("****-1.退出*****\n");
    printf("******************\n");
}


void test()
{
    queue pq;
    QueueInit(&pq);
    int input=0,x=0;
    do
    {
        menu();
       printf("请选择\n");
       scanf("%d",&input);
       switch(input)
       {
        case 1: //插入
        printf("请输入插入的数据\n");
        scanf("%d",&x);
        QueuePush(&pq,x);
        break;
        case 2: //删除
        QueuePop(&pq);
        printf("删除成功\n");
        break;
        case 3: //返回头
        printf("头节点是%d\n",QueueFront(&pq));
        break;
        case 4: //返回尾
        printf("尾节点是%d\n",QueueBack(&pq));
        break;
        case 5: //返回大小
        printf("大小是%d\n",QueueSize(&pq));
        break;
        case 6: //是否为空
        printf("%s\n",QueueEmpty(&pq)?"true":"false");
        break;
        case 7: //打印
        while(!QueueEmpty(&pq))
        {
            printf("%d ",QueueFront(&pq));
            QueuePop(&pq);
        }
        printf("\n");
        break;
       case -1: //退出
       printf("退出成功\n");
       break;
       default :
       printf("选择错误，请重新选择\n");
       break;
       } 

    } while (input!=-1);
    

    QueueDestroy(&pq);

}

int main()
{

    test();
    return 0;
}