#include<stdio.h>
#include<malloc.h>

const int maxsize = 1024;
typedef char datatype;
typedef struct node {
	datatype data;
	struct node *lchild, *rchild;
} bitree;

bitree* createtree();
bitree* preorder_delete(bitree*, datatype);
void preorder(bitree *);
int main(void)
{
	bitree *pa, *pb;
	datatype x;

	printf("Please create your bitree:\n");
	pa = createtree();

	printf("The bitree that you input is:\n");
	preorder(pa);
	printf("\n");

	printf("Please input your char that you want to delete:\n");
	getchar();

	x = getchar();
	pb = preorder_delete(pa, x);
	printf("The bitree after you delete:\n");
	preorder(pa);
	printf("\n");

	printf("The bitree that you delete:\n");
	preorder(pb);
	printf("\n");

	printf("\n");
	return 0;
}

bitree *createtree()
{
	char ch;
	bitree *Q[maxsize];
	int front, rear;
	bitree *root, *s;
	root = NULL;
	front = 1;
	rear = 0;

	while ((ch = getchar()) != '#') {
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
			if (s && Q[front]) {
				if (rear % 2 == 0) 
					Q[front]->lchild = s;
				else 
					Q[front]->rchild = s;
			}
			if (rear % 2 == 1) front++;
		}
	}
	return root;
}

void preorder(bitree* T)
{
	if (T != NULL) {
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

bitree* preorder_delete(bitree* T, datatype d)
{
	if (T == NULL) return NULL;
	if (T != NULL ) {
		if (T->lchild != NULL && T->lchild->data == d) {
			bitree* temp;
			temp = T->lchild;
			T->lchild = NULL;
			return temp;
		} else if (T->rchild != NULL && T->rchild->data == d) {
			bitree* temp;
			temp = T->rchild;
			T->rchild = NULL;
			return temp;
		}
	}
	preorder_delete(T->lchild, d);
	preorder_delete(T->rchild, d);	
}
