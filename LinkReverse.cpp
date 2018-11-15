#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int Element;
typedef struct Node* Ptr;
struct Node{
	Element data;
	Ptr next;
};
typedef Ptr List; //������list
//���������
List read() {
	//List L;
	int m=0; //�������м����ڵ�
	int n = 0;//ÿ���ڵ�ľ����ֵ
	Ptr list=NULL;
	Ptr last=NULL;
	printf("�����빲�м����ڵ㣺");
	scanf_s("%d", &m);
	if (m==0){
		return NULL;
	}
	scanf_s("%d",&n);
	list =(Ptr)malloc(sizeof(struct Node));
	list->data = n;
	list->next = NULL;
	last = list;
	m--; //���ȼ�һ
	while (m) {
		//printf("������ڵ�ľ����ֵ��");
		scanf_s("%d",&n);
		Ptr node = (Ptr)malloc(sizeof(struct Node));
		node->data = n;
		node->next = NULL;
		last->next=node;
		last = node; //�����ƶ�
		m--;
	}
	return list;
}
void print(List L) {
	if (L==NULL) {
		printf("����Ϊ�գ�");
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
//��������ת
List reverse(List L) {
	Ptr t = NULL;
	Ptr newlist = NULL;
	if (L==NULL){
		printf("����Ϊ�գ�");
		return NULL;
	}
	while (L!=NULL) {
		t = L->next;//����L����һ���ڵ�
		L->next = newlist; //newlistָ��Lǰһ���ڵ�
		newlist = L;  //ָ����ת�����һ���ڵ�
		L = t;//L����һ���ڵ��ƶ�
		//printf("%d",L);
	}
	return newlist;
}
int main() {
	List L1, L2;
	L1 = read();
	L2 = reverse(L1);
	print(L1);
	printf("��ת������Ϊ��\n");
	print(L2);
	system("pause");
	return 0;
}