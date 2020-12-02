//交换左右子树，先序遍历递归实现
#include<stdio.h>
#include<malloc.h>

//二叉链表的结构类型定义
const int MAXSIZE = 1024;
typedef char datatype;
typedef struct node {
	datatype data;
	struct node *lchild, *rchild;
} bitree;

bitree *createtree();
void preorder(bitree *);
void swap(bitree *);

int main(void)
{
	bitree *pb;
	pb = createtree();
	
	printf("交换之前的原二叉树的先序遍历序列为：");
	preorder(pb);
	printf("\n");
	
	swap(pb);
	printf("交换之后的原二叉树的先序遍历序列为：");
	preorder(pb);
	
	printf("\n");
	return 0;
}

bitree *createtree()
{
	char ch;
	bitree *Q[MAXSIZE];
	int front, rear;
	bitree *root, *s;
	root = NULL;
	front = 1;
	rear = 0;

	while ((ch = getchar())!='#') {
		s = NULL;
		if (ch != '@') {
			s = (bitree*) malloc(sizeof(bitree));
			s->data = ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if (rear == 1)
			root = s;
		else {
			if (s && Q[front])
				if (rear % 2 == 0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;
			if (rear % 2 == 1) front++;
		}
	}
	return root;
}
void preorder(bitree * p)
{
	if (p!=NULL) {
		printf("%c", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void swap(bitree * T)
{
	if (T == NULL) {
		return;
	}
	bitree* temp;
	temp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = temp;

	swap(T->lchild);
	swap(T->rchild);
}
