#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* Next;
};

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void insert(int x, List L, Position);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int x, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void DataInsert(List L, int target, int data);
void PrintList(List L);
int main() {
	char command;
	int x, y;
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	Position output;

	while (1) {
		scanf("%c", &command);
		
		switch (command) {
		case 'i':
			scanf("%d %d", &x, &y);
			if (y != -1) {
				DataInsert(L, y, x);
			}
			else {
				DataInsert(L, -1, x);
			}
			break;
		
		case 'd':
			scanf("%d",&x);
			Delete(x, L);
			break;
		
		case 'f':
			scanf("%d", &x);
			output = FindPrevious(x, L);
			printf("%d\n", output->data);
			break;
		
		case 'p':
			
			PrintList(L);
			break;
		
		case 'q':
			break;
		}
		
	}
	return 0;
}

void insert(int x, List L, Position P) {
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL) {
		printf("Out of space!!");
	}
	
	TmpCell->data = x;
	
	TmpCell->Next = NULL;

	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

int IsEmpty(List L) {
	int res;
	if (L->Next == NULL) res= 1;
	else res= -1;

	return res;
}

int IsLast(Position P, List L) {
	if (P->Next == NULL) return 1;
	else return -1;
}

Position Find(int x, List L) {
	Position P;
	P = L->Next;
	
	while (P != NULL && P->data != x) {
		P = P->Next;
	}

	return P;
}

void Delete(int X, List L) {
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (IsLast(P, L)!=1) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

Position FindPrevious(int X, List L) {
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->data != X) {
		P = P->Next;
	}
	return P;
}

/* insert a new node with the key ¡°x¡± 
after the node with the key ¡°y¡± */
void DataInsert(List L, int target, int data) {
	Position P;

		if (target == -1) {
			insert(data, L, L);
		}
		else {
			P = Find(target, L);
			insert(data, L, P);
		}
}


void PrintList(List L) {
	Position P = L;
	
	
	
		for (; P->Next != NULL;) {
			printf("%d->", P->Next->data);
			P = P->Next;
		}
	
	 printf("NULL\n");
	
}