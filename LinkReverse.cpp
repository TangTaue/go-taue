#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int Element;
typedef struct Node* Ptr;
struct Node{
	Element data;
	Ptr next;
};
typedef Ptr List; //单链表list
//单链表读入
List read() {
	//List L;
	int m=0; //单链表有几个节点
	int n = 0;//每个节点的具体的值
	Ptr list=NULL;
	Ptr last=NULL;
	printf("请输入共有几个节点：");
	scanf_s("%d", &m);
	if (m==0){
		return NULL;
	}
	scanf_s("%d",&n);
	list =(Ptr)malloc(sizeof(struct Node));
	list->data = n;
	list->next = NULL;
	last = list;
	m--; //长度减一
	while (m) {
		//printf("请输入节点的具体的值：");
		scanf_s("%d",&n);
		Ptr node = (Ptr)malloc(sizeof(struct Node));
		node->data = n;
		node->next = NULL;
		last->next=node;
		last = node; //往后移动
		m--;
	}
	return list;
}
void print(List L) {
	if (L==NULL) {
		printf("链表为空！");
		return ;
	}
	while (L!=NULL) {
		printf("%d", L->data);
		L = L->next;
		printf(" ");
	}
	printf("\n");
	return;
}
//单链表逆转
List reverse(List L) {
	Ptr t = NULL;
	Ptr newlist = NULL;
	if (L==NULL){
		printf("链表为空！");
		return NULL;
	}
	while (L!=NULL) {
		t = L->next;//保存L的下一个节点
		L->next = newlist; //newlist指向L前一个节点
		newlist = L;  //指向逆转的最后一个节点
		L = t;//L向下一个节点移动
		//printf("%d",L);
	}
	return newlist;
}
int main() {
	List L1, L2;
	L1 = read();
	L2 = reverse(L1);
	print(L1);
	printf("逆转的链表为：\n");
	print(L2);
	system("pause");
	return 0;
}