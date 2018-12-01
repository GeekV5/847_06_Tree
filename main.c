//第 6 章 树
#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

//链式存储结构
typedef struct BTNode
{
    char data;     //这里默认结点data域为char型，如果题目中需要其他类型，则只需修改此处
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

//遍历二叉树的结点值
void Visit(BTNode *p)
{
    printf("%c",p->data);
}

//先序遍历创建二叉树
void CreateBiTree(BTNode *bt)
{
    char ch;
    scanf("%c",&ch);
    if(ch == ' ')
    {
        bt = NULL;
    }
    if(ch == '#')
    {
        return;
    }
    else{
        bt = (BTNode*)malloc(sizeof(BTNode));
        if(!(bt))
        {
            exit(-1);
        }
        bt->data = ch;
        CreateBiTree(&bt->lchild);
        CreateBiTree(&bt->rchild);
    }
}

//先序递归遍历二叉树
void PreOrder(BTNode *bt)
{
    if(bt != NULL)
    {
        Visit(bt);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//二叉树先序遍历非递归算法
void PreOrderNonRecursion(BTNode *bt)
{
    if(bt != NULL)
    {
        BTNode *Stack[maxSize]; //定义一个栈
        int top = -1;//初始化栈
        BTNode *p;
        Stack[++top] = bt;//根结点入栈
        while(top != -1)//栈空循环退出，遍历结束
        {
            p = Stack[top--];//出栈并输出栈顶结点
            Visit(p);//Visit为访问p的函数
            if(p->rchild != NULL)//栈顶结点的右孩子存在，则右孩子入栈
            {
                Stack[++top] = p->rchild;
            }
            if(p->lchild != NULL)//栈顶结点的左孩子存在，则左孩子入栈
            {
                Stack[++top] = p->lchild;
            }
        }

    }
}

//二叉树中序遍历非递归算法
void InOrderNonRecursion(BTNode *bt)
{
    if(bt != NULL)
    {
        BTNode *Stack[maxSize];
        int top = -1;
        BTNode *p;
        p = bt;
        while(top != -1 || p != NULL)
        {
            while(p != NULL)
            {
                Stack[++top] = p;
                p= p->lchild;
            }
            if(top != NULL)
            {
                p = Stack[top--];
                Visit(p);
                p = p->rchild;
            }
        }
    }
}

//二叉树后序遍历非递归算法
void PostOrderNonRecursion(BTNode *bt)
{
    if(bt != NULL)
    {
        BTNode *Stack1[maxSize];
        int top1 = -1;
        BTNode *Stack2[maxSize];
        int top2 = -1;
        BTNode *p = NULL;
        Stack1[++top1] = bt;
        while(top1 != -1)
        {
            p = Stack1[top1--];
            Stack2[++top2] = p;
            if(p->lchild != NULL)
            {
                Stack1[++top1] = p->lchild;
            }
            if(p->rchild != NULL)
            {
                Stack1[++top1] = p->rchild;
            }
        }
        while(top2 != -1)
        {
            p = Stack2[top2--];
            Visit(p);
        }

    }
}



int main() {
    printf("欢迎来到二叉树世界!\n");
    BTNode *bitreenode;
    CreateBiTree(&bitreenode);
    PreOrder(bitreenode);
    return 0;
}