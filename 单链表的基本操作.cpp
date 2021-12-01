#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef int Status;

#define overflow -2
#define true 1
#define false 0
#define ok 1
#define error 0
//单链表的储存结构
typedef struct Node {
	Elemtype data;
	struct Node *next;
} Node, *linklist;
Status createlist(linklist &L, int n) { //头插法创建新链表
	L = (Node *)malloc(sizeof(Node));
	Node *temp = L;
	temp->next = NULL;
	for (int i = 0; i <n; i++) {
		Node *p = (Node *)malloc(sizeof(Node));
		scanf("%d", &p->data);
		p->next = temp->next;
		temp->next = p;
	}
	return ok;
}
Status createlist2(linklist &L, int n) {
	Node *p;
	L = (Node *)malloc(sizeof(Node));
	Node *temp=L;
	temp->next=NULL;
	for (int i = n; i > 0; i--) {
		Node *p = (Node *)malloc(sizeof(Node));
		scanf("%d", &p->data);
		temp->next=p;
		temp=p;
	}
	temp->next=NULL;
	return ok;
}
Status deletelist(linklist &L, int i) { //去除单链表中位置i上的结点
	Node *p = (Node *)malloc(sizeof(Node));
	p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) {
		printf("error");
	}
	p->next = p->next->next;
	return ok;
}
Status listempty(linklist &L) { //检查链表是否为空
	if (L != NULL && L->next == NULL) {
		printf("empty list!\n");
		return ok;
	} else
		return error;
}
void printlist(linklist &L) { //输出链表各结点的data
	Node *temp;
	temp = L;
	while (temp->next!=NULL) {
		temp = temp->next;
		printf("%d",temp->data);
		printf(" ");
	}
	printf("\n");
}
Status lengthlist(linklist &L) { //求链表的长度
	linklist p;
	int i;
	if (L) {
		i = 0;
		p = L->next;
		while (p != NULL) {
			i++;
			p = p->next;
		}
	}
	return i;
}
int main() {

	linklist L;
	int i;
	int n;
	scanf("%d",&n);
	createlist2(L,n);
	printlist(L);
//	for (i = 1; i <= lengthlist(L); i++) {
//		deletelist(L, 1);
//		listempty(L);
//		printlist(L);
//	}
	return 0;
}
