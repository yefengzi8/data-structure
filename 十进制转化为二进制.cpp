#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define STACKINCREMENT 10
#define overflow -1
#define ok 1
#define error 0
typedef int Elemtype;
typedef int Status;
typedef struct stack
{
    Elemtype *top;
    Elemtype *base;
    int stacksize;
} stack;

Status lnitstack(stack &s)
{
    s.base = (Elemtype *)malloc(sizeof(Elemtype));
    if (!s.base)
    {
        exit(overflow);
    }
    s.top = s.base;
    s.stacksize = 100;
}
Status clearstack(stack &s)
{
    s.top = s.base;
}
Status stackempty(stack &s)
{
    if (s.top == s.base)
    {
        printf("栈已空");
    }
    else
    {
        return error;
    }
}
Status lengthstack(stack &s)
{
    return s.top - s.base;
}
Status push(stack &s, int e)
{
    if (s.top - s.base >= s.stacksize)
    {
        printf("栈已满，无法再放入");
    }
    else
    {
        *s.top++ = e;
    }
}
Status pop(stack &s, int &e)
{
    if (s.top == s.base)
    {
        printf("栈已空");
    }
    else
    {
        e = *--s.top;
    }
    return ok;
}
Status gettop(stack s, int &e)
{
    if (s.top == s.base)
    {
        return error;
    }
    e = *(s.top - 1);
    return ok;
}
int main()
{
    stack s;
    lnitstack(s);
    int n, e, i;
    printf("请输入一个十进制数");
    scanf("%d", &n);
    while (n != 0)
    {
        i = n % 2;
        push(s, i);
        n = n / 2;
    }
    int l = lengthstack(s);
    for (i = 0; i < l; i++)
    {
        gettop(s, e);
        printf("%d ", e);
        pop(s, e);
    }
}
