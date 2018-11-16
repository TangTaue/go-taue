#include <stdio.h>
#include <iostream>
#define true 1

using namespace std;
typedef struct Tnode* Tree;
struct Tnode {
	int v;  //数据元素 
	Tree Left, Right; //左右指针
	int flag;  //标志位
};
Tree NewNode(int V){ //分配节点
	Tree T = (Tree)malloc(sizeof(struct Tnode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}
//二叉搜索树的插入
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
	printf("请输入根节点的值：");
	scanf_s("%d", &V);
	T = NewNode(V);
	//n-1个剩余的值插入
	for (i = 1; i < N; i++) {
		scanf_s("%d", &V);
		T = insert(T, V);  //判断后继节点与根节点的大小关系
	}
	return T;
}
//递归查找树
int check(Tree T,int V) {
	if (T->flag) {
		if (V<T->v) {
			//左递归
			return check(T->Left,V);
		}
		else if (V>T->v){
			//右递归
			return check(T->Right,V);
		}
		else {
			return 0;
		}
	}
	//flag的值为0,之前并未找到该点
	else{
		if (T->v==V) {
			printf("查找成功！");
			T->flag = 1;
			return 1;
		}
		else {
			return 0;
		}
	}
}
//清除T中的各节点的flag标记
void Reset(Tree T) {
	if (T->Left) Reset(T->Left);
	if (T->Right) Reset(T->Right);
	T->flag = 0;
}
//释放当前节点的空间
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

//判别序列的每一个树是否相等
int Jduge(Tree T,int N) {
	//此时的flag是判别序列是否已经读取完全之后再退出，否则序列的判别会出现问题。
	int i, V, flag=0;  //初始值为0   //flag=0时表明当前的判别是一致的，flag=1是表明当前的判别出现不一致。
	scanf_s("%d",&V);
	if (V != T->v) flag = 1;
	else T->flag=1; //节点已被访问 设标志位为1
	//之后的N-1个序列
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
	//N为节点个数，L为序列个数
	int N, L, i;
	printf("请输入节点数和要判别的序列数：");
	scanf_s("%d",&N);
	while (N){
		scanf_s("%d",&L);
		//构建二叉搜索树
		T = MakeTree(N);
		for (i = 1; i < L;i++){  //依次判别L个序列是否相等
			if (Jduge(T,N))printf("yes");
			else printf("No");
			Reset(T);  //重置flag的值
		}
		FreeTree(T);
		scanf_s("%d",&N);
	}
	//system("pause");
	return 0;
}
 

