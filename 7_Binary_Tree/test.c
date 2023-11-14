#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"queue.h"
typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}BTNode;


void PreOrder(BTNode* root) //前序遍历
{
    if(root==NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);

}


void InOrder(BTNode* root) //中序遍历
{
    if(root==NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(BTNode* root)
{
    if(root==NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}


int TreeSize(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

// int TreeSize(BTNode* root)  //多次调用存在问题，count在程序的运行的整个生命周期都存在会累加
// {
//     static int count=0;
//     if(root==NULL)
//     {
//         return count;
//     }
//     count++;
//     TreeSize(root->left);
//     TreeSize(root->right);
//     return count;
// }

int BTreekNode(BTNode* root,int k) //二叉树第k层节点个数
{
    if(root==NULL)
        return 0;
    if(k==1)
        return 1;
    return BTreekNode(root->left,k-1)+BTreekNode(root->right,k-1);
}

BTNode* BTreeFind(BTNode*root,int x) //返回值为x的节点
{
    BTNode* lnode,*rnode;
    if(root==NULL)
        return NULL;
    if(root->data==x)
        return root;
    lnode=BTreeFind(root->left,x);
    if(lnode)
        return lnode;
    rnode=BTreeFind(root->right,x);
    if(rnode)
        return rnode;

    return NULL;
}

void BTreeDestroy(BTNode* root)
{
    if(root==NULL)
        return;
    BTreeDestroy(root->left);
    BTreeDestroy(root->right);
    free(root);
}

void TreeLevelOrder(BTNode*root) //层次遍历，利用队列的特性
{
    if(root==NULL)
    {
        printf("NULL\n");
        return ;
    }
        
    queue q;
    QueueInit(&q);
    QueuePush(&q,root);
    while(!QueueEmpty(&q))
    {
        BTNode* front=QueueFront(&q);
        printf("%d ",front->data);
        QueuePop(&q);
        if(front->left)
        QueuePush(&q,front->left);
        if(front->right)
        QueuePush(&q,front->right);
    }
    QueueDestroy(&q);
    printf("\n");
}

bool BinaryTreeComplete(BTNode* root) //判断是不是完全二叉树
{
    if(root==NULL)
        return true;
    queue q;
    QueueInit(&q);
    QueuePush(&q,root);
    while(!QueueEmpty(&q))
    {

        BTNode* front=QueueFront(&q);
        QueuePop(&q);
        if(front)
        {
            QueuePush(&q,front->left);
            QueuePush(&q,front->right);

        }
        else
        {
            break;
        } 
    }


	// 遇到空以后，后面全是空，则是完全二叉树
	// 遇到空以后，后面存在非空，则不是完全二叉树
    while(!QueueEmpty(&q))
    {
        BTNode* front=QueueFront(&q);
        QueuePop(&q);
        if(front!=NULL)
        {
            QueueDestroy(&q);
            return false;
        }
    }

    QueueDestroy(&q);
    return true;
}


BTNode* BuyNode(BTDataType x)
{
    BTNode* newnode=(BTNode*)malloc(sizeof(BTNode));
    assert(newnode);
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int main()
{
    
    BTNode *n1=BuyNode(1);   
    BTNode *n2=BuyNode(2);
    BTNode *n3=BuyNode(3);
    BTNode *n4=BuyNode(4);
    BTNode *n5=BuyNode(5);
    BTNode *n6=BuyNode(6);
    BTNode *n7=BuyNode(7);

    n1->left=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n6->right=n7;
 
    PreOrder(n1);
    printf("\n");
    InOrder(n1);
    printf("\n");
    PostOrder(n1);
    printf("\n");
    TreeLevelOrder(n1);
    int size=TreeSize(n1);
    printf("%d\n",size);
    int size1=TreeSize(n1);
    printf("%d\n",size1);
    int ret=BTreekNode(n1,3);
    printf("%d\n",ret);

    BTNode* find=BTreeFind(n1,4);
    printf("%d\n",find->data);

    bool complete=BinaryTreeComplete(n1);
    printf("%d ",complete);
    BTreeDestroy(n1);
    return 0;
}