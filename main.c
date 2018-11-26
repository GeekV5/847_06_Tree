//第 6 章 树
#include <stdio.h>

//链式存储结构
typedef struct BTNode
{
    char data;     //这里默认结点data域为char型，如果题目中需要其他类型，则只需修改此处
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

void Visit(BTNode *p)
{
    printf("%c",p->data);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}