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

typedef struct Stack
{
    Elemtype *base;
    Elemtype *top;
    int Stacksize;
} Stack;

Status lnitstack(Stack &s)
{
    s.base = (Elemtype *)malloc(sizeof(Elemtype));
    if (!s.base)
        exit(overflow);
    s.top = s.base;
    s.Stacksize = 100;
    return ok;
}
Status clearstack(Stack &s)
{
    s.top = s.base;
}
Status stackempty(Stack &s)
{
    if (s.base == s.top)
    {
        printf("栈已空");
    }
    else
    {
        return error;
    }
}
Status stacklength(Stack s){
     return s.top-s.base;
}
Status push(Stack &s, int e)
{
    if (s.top - s.base >= s.Stacksize)
    {
        printf("栈已满，无法再放入");
        return error;
    }
    else
    {
        *s.top++ = e;
        return ok;
    }
}
Status gettop(Stack s, int &e)
{
    if (s.top == s.base)
    {
        return error;
    }
    e = *(s.top - 1);
    return ok;
}
Status pop(Stack &s, int &e)
{
   if(s.top==s.base){
       printf("栈已空");
   }else{
     e=*--s.top;
   }
   return ok;
}
Status stacktraverse(Stack s, Status(*visit)(int))
{
    Elemtype* p;
    p = s.base;
    while (p != s.top)
    {
        if (!visit(*p))
            return error;
        p++;
    }
    return ok;
}
Status printelem(Elemtype e)
{
    printf("%d\t", e);
    return ok;
}
int main(){
Stack s;
lnitstack(s);
int e,n,i;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&e);
    push(s,e);
}
stacktraverse(s,printelem);
return 0;
}