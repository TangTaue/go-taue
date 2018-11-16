#include <stdio.h>
#include <iostream>
#define true 1

using namespace std;
typedef struct Tnode* Tree;
struct Tnode {
	int v;  //����Ԫ�� 
	Tree Left, Right; //����ָ��
	int flag;  //��־λ
};
Tree NewNode(int V){ //����ڵ�
	Tree T = (Tree)malloc(sizeof(struct Tnode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}
//�����������Ĳ���
Tree insert(Tree T, int V) {
	if (!T) {
		T=NewNode(V);
	}
	else {
		if (V>T->v) {
			T->Right = insert(T->Right, V);
		}
		else {
			T->Left = insert(T->Left, V);
		}
	}
	return T;
}
Tree MakeTree(int N) {
	Tree T;
	int i, V;
	printf("��������ڵ��ֵ��");
	scanf_s("%d", &V);
	T = NewNode(V);
	//n-1��ʣ���ֵ����
	for (i = 1; i < N; i++) {
		scanf_s("%d", &V);
		T = insert(T, V);  //�жϺ�̽ڵ�����ڵ�Ĵ�С��ϵ
	}
	return T;
}
//�ݹ������
int check(Tree T,int V) {
	if (T->flag) {
		if (V<T->v) {
			//��ݹ�
			return check(T->Left,V);
		}
		else if (V>T->v){
			//�ҵݹ�
			return check(T->Right,V);
		}
		else {
			return 0;
		}
	}
	//flag��ֵΪ0,֮ǰ��δ�ҵ��õ�
	else{
		if (T->v==V) {
			printf("���ҳɹ���");
			T->flag = 1;
			return 1;
		}
		else {
			return 0;
		}
	}
}
//���T�еĸ��ڵ��flag���
void Reset(Tree T) {
	if (T->Left) Reset(T->Left);
	if (T->Right) Reset(T->Right);
	T->flag = 0;
}
//�ͷŵ�ǰ�ڵ�Ŀռ�
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

//�б����е�ÿһ�����Ƿ����
int Jduge(Tree T,int N) {
	//��ʱ��flag���б������Ƿ��Ѿ���ȡ��ȫ֮�����˳����������е��б��������⡣
	int i, V, flag=0;  //��ʼֵΪ0   //flag=0ʱ������ǰ���б���һ�µģ�flag=1�Ǳ�����ǰ���б���ֲ�һ�¡�
	scanf_s("%d",&V);
	if (V != T->v) flag = 1;
	else T->flag=1; //�ڵ��ѱ����� ���־λΪ1
	//֮���N-1������
	for (i = 1; i < N; i++) {
		scanf_s("%d",&V);
		if ((!flag)&&(!check(T,V))){
			flag = 1;
		}
	}
	if (flag) return 0;
	else return 1;
}
int main() {
	Tree T;
	//NΪ�ڵ������LΪ���и���
	int N, L, i;
	printf("������ڵ�����Ҫ�б����������");
	scanf_s("%d",&N);
	while (N){
		scanf_s("%d",&L);
		//��������������
		T = MakeTree(N);
		for (i = 1; i < L;i++){  //�����б�L�������Ƿ����
			if (Jduge(T,N))printf("yes");
			else printf("No");
			Reset(T);  //����flag��ֵ
		}
		FreeTree(T);
		scanf_s("%d",&N);
	}
	//system("pause");
	return 0;
}
 

