#include<stdio.h>
#include<stdlib.h>
struct AVlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
struct AvlNode {
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};


static int Height(Position P);
int Max(int a, int b);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position DoubleRotateWithRight(Position K3);
AvlTree Insert(int X, AvlTree T);
void inorder(AvlTree T);

int main() {
	int num;
	char c;
	AvlTree T = NULL;
	while (1) {
		scanf("%c", &c);
		switch (c) {
		case 'i':
			scanf("%d", &num);
			T=Insert(num, T);
			break;
		case 'p':
			inorder(T);
			printf("\n");
			break;

		}
		while (getchar() != '\n');
	}
	return 0;
}

static int Height(Position P) {
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

static int Max(int a, int b) {
	if (a > b)return a;
	else return b;
}
static Position SingleRotateWithLeft(Position K2) {
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	
	return K1;
}

static Position SingleRotateWithRight(Position K2) {
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

	return K1;
}

static Position DoubleRotateWithLeft(Position K3) {
	K3->Left = SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3) {
	K3->Right = SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight(K3);
}

AvlTree Insert(int X, AvlTree T) {
	if (T == NULL) {
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL) {
			printf("Out of Space!!\n");
		}
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = NULL;
			T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) {
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}else{
		if (X > T->Element) {
			T->Right = Insert(X, T->Right);
			if (Height(T->Right) - Height(T->Left) == 2) {
				if (X > T->Right->Element)
					T = SingleRotateWithRight(T);
				else
					T = DoubleRotateWithRight(T);
			}
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
	
}

void inorder(AvlTree T) {
	if (T) {
		inorder(T->Left);
		printf("%d(%d) ",T->Element,T->Height);
		inorder(T->Right);
	}
}