//第 6 章 树
#include <stdio.h>
#include <stdlib.h>

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

//先序遍历二叉树
void PreOrder(BTNode *bt)
{
    if(bt != NULL)
    {
        Visit(bt);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

int main() {
    printf("欢迎来到二叉树世界!\n");
    BTNode *bitreenode;
    CreateBiTree(&bitreenode);
    PreOrder(bitreenode);
    return 0;
}