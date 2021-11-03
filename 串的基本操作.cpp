#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct string
{
    char ch[MAXSIZE + 1];
    int length;
} string;

int stringassign(string *s, char chs[])//生成一个字符串
{
    int i = 0;
    while (chs[i] != '\0')
    {
        s->ch[i] = chs[i];
        ++i;
    }
    s->length = i;
    return 0;
}
int stringcopy(string *s1, string *s2)//把字符串s2复制给字符串s1
{
    int i = 0;
    for (i = 0; i < s2->length; i++)
    {
        s1->ch[i] = s2->ch[i];
    }
    s1->length = s2->length;
    return 0;
}
int stringempty(string *s)//检验字符串是否为空串
{
    if (s->length == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int stringlength(string *s)//求字符串的长度
{
    return s->length;
}
int showstring(string *s)//展示字符串
{
    if (s->length == 0)
    {
        printf("当前串已空");
        return 0;
    }
    else
    {
        int i = 0;
        for (i = 0; i < s->length; i++)
        {
            printf("%c", s->ch[i]);
        }
        printf("\n");
        return 0;
    }
}
int stringcompare(string *s1, string *s2)//比较字符串s1和s2
{
    int i = 0;
    while ((i < s1->length) && (i < s2->length))
    {
        if ((int)s1->ch[i] > (int)s2->ch[i])
        {
            return 1;
        }
        if ((int)s2->ch[i] > (int)s1->ch[i])
        {
            return -1;
        }
        if (s1->ch[i] == s2->ch[i])
        {
            ++i;
            continue;
        }
        ++i;
    }
    if (i == s1->length && i != s2->length)
    {
        return 1;
    }
    else if (i == s2->length && i != s2->length)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int concat(string *s, string *s1, string *s2)//用s返回s1和s2连接而成的字符串
{
    int i, j;
    for (i = 0; i < s1->length; i++)
    {
        s->ch[i] == s1->ch[i];
    }
    s->length = s1->length;
    for (j = 0; j < s2->length; j++)
    {
        s->ch[s->length] = s2->ch[j];
        ++s->length;
    }
    return 0;
}
int substring(string *sub, string *s, int pos, int len)//用sub返回字符串s中pos起长度为len的字符串
{
    if (pos < 1 || pos > s->length || len < 0 || (len > s->length - pos + 1))
    {
        printf("输入有误");
        return 0;
    }
    int j = 0;
    while (j < len)
    {
        sub->ch[j] = s->ch[pos - 1];
        ++j;
        ++pos;
    }
    sub->length = len;
    return 0;
}
int stringinsert(string *s1, int pos, string *s2)//在串s1的第pos位置之前插入字符串s2
{
    if (pos < 1 || pos > s1->length)
    {
        printf("输入有误");
        return 0;
    }
    int i;
    for (i = (s1->length - 1); i >= pos - 1; i++)
    {
        s1->ch[i + s2->length] = s1->ch[i];
    }
    int j = 0;
    int k = pos - 1;
    for (j = 0; j < s2->length; j++)
    {
        s1->ch[k] = s2->ch[j];
        k++;
    }
    s1->length += s2->length;
    return 0;
}
int stringdelete(string *s, int pos, int len)//
{
    if (pos < 1 || pos > (s->length - len + 1))
    {
        printf("输入有误！");
        return 0;
    }
    int i;
    for (i = pos + len; i <= s->length; i++)
    {
        s->ch[i - len - 1] = s->ch[i - 1];
    }
    s->length -= len;
    return 0;
}
void getnext(string *t, int *next)
{
    int i, j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < t->length)
    {
        if (j == 0 || t->ch[i - 1] == t->ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int index_kmp(string *s, string *t, int pos)
{
    int i = pos;
    int j = 0;
    int next[255];
    getnext(t, next);
    while (i <= s->length && j <= t->length)
    {
        if (j == 0 || s->ch[i] == t->ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > t->length)
    {
        return i - t->length;
    }
    else
    {
        return 0;
    }
}
int stringreplace(string *s,string *t,string *r){
    int i;
    int flag;
    for(i=0;i<s->length;i++){
        int j=0;
        flag=1;
        while(t->ch[j]==s->ch[i]){
            i++;
            j++;
        }
        if(j==t->length){
           flag=0;
        }
        if(flag=0){
            
        }
    }
}
int main(){
  string s;
  string r;
  char ch[]={"hello world"};
  stringassign(&s,ch);
  showstring(&s);
}
