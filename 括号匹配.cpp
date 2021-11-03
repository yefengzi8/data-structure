#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Elemtype;
typedef char Status;
#define ok 0;
#define error 1;
#define overflow -1;
typedef struct stack {
	Elemtype *top;
	Elemtype *base;
	int stacksize;
} stack;
Status lnitstack(stack &s) {
	s.base = (Elemtype *)malloc(sizeof(Elemtype));
	if (!s.base) {
		return overflow;
	}
	s.top = s.base;
	s.stacksize = 100;
}
Status push(stack &s, char e) {
	if (s.top - s.base > s.stacksize) {
		printf("栈已满");
	} else {
		*s.top++ = e;
	}
	return ok;
}
Status pop(stack &s, char &e) {
	if (s.top == s.base) {
		printf("栈已空");
	} else {
		e = *--s.top;
		return e;
	}
}
Status gettop(stack s, char &e) {
	if (s.top == s.base) {
		printf("栈已空");
	}
	e = *(s.top - 1);
}
Status stackempty(stack &s) {
	if (s.top == s.base) {
		return 0;
	} else {
		return 1;
	}
}
int check(char *str) {
	char e;
	stack s;
	int q=0;
	lnitstack(s);
	for (int i = 0; i < strlen(str); i++) {
		char a = str[i];
		switch (a) {
			case '(':
			case '[':
			case '{':
				push(s, a);
				break;
			case ')':
				if (pop(s,e) != '(') {
					 q=1;
				}
				break;
			case ']':
				if (pop(s,e) != '[') {
					 q=1;
		
				}
				break;
			case '}':
				if (pop(s,e) != '{') {
					 q=1;
		
				}
				break;
		}
	}
	int flag=stackempty(s);
	if(flag==0&&q==0) {
		return 0;
	} else {
		return 1;
	}

}
int main() {
	char str[100];
	printf("请输入一个字符串\n");
	gets(str);
	int flag=check(str);
	if (flag==0) {
		printf("yes");
	} else {
		printf("no");
	}
	return 0;
}
