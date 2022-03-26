#include <stdio.h>
#include <stdlib.h>
typedef int Status;
typedef int Elemtype;
#define ok 1;
#define error 0;
typedef struct BiTNode
{
    Elemtype data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;
void createBiTree(BiTree *t)
{
    Elemtype data;
    scanf("%d", &data);
    if (data == -1)
    {
        *t = NULL;
    }
    else
    {
        *t = (BiTree)malloc(sizeof(BiTNode));
        if (!(*t))
        {
            printf("内存分配失败\n");
            exit(-1);
        }
        (*t)->data = data;
        createBiTree(&(*t)->lchild);
        createBiTree(&(*t)->rchild);
    }
}

void xianxu(BiTree t)
{
    if (t == NULL)
    {
        return;
    }
    printf("%d", t->data);
    xianxu(t->lchild);
    xianxu(t->rchild);
}
void zhongxu(BiTree t)
{
    if (t == NULL)
    {
        return;
    }
    printf("%d", t->data);
    zhongxu(t->lchild);
    printf("%d", t->data);
    zhongxu(t->rchild);
}
void houxu(BiTree t)
{
    if (t == NULL)
    {
        return;
    }
    houxu(t->lchild);
    houxu(t->rchild);
    printf("%d", t->data);
}
int main()
{
    BiTree t;
    printf("请输入数据\n"); //以前序遍历的方式输入。类似输入 1 2 -1 3 -1 -1 4 -1 -1
    createBiTree(&t);
    xianxu(t);
    return 0;
}
