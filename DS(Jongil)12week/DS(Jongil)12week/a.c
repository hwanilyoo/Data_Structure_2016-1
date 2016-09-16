#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct ListNode * position;
typedef position List;
typedef struct HashTbl * HashTable;
int hx(int key, HashTable H);
HashTable createHash(int size, float A);
position Find(int key, HashTable H);
position FindPrevious(int key, HashTable H);
void Insert(int key, HashTable H);
void Delete(int key, HashTable H);
int hx(int key, HashTable H);
void Print(HashTable H);
struct ListNode {
	int Element;
	position Next;
};

struct HashTbl {
	int TableSize;
	float A;
	List * TheLists;
};
int main() {
	HashTable H = NULL;
	int ts,input;
	float A;
	int ff;
	char command;
	printf("Hash table size : ");
	scanf("%d", &ts);
	printf("A : ");
	scanf("%f",&A);
	H=createHash(ts, A);
	while (getchar() != '\n');
	while (1) {
		scanf("%c",&command);
		switch (command) {
		case 'i':
			scanf("%d",&input);
			while (getchar() != '\n');
			Insert(input, H);
			break;
		case 'd':
			scanf("%d", &input);
			while (getchar() != '\n');
			Delete(input, H);
			break;
		case 'f':
			scanf("%d", &input);
			while (getchar() != '\n');
			ff=Find(input, H);
			if (ff != NULL) {
				printf("Find %d in Hasn[%d]\n", input, hx(input, H));
			}
			break;
		case 'p':
			Print(H);
			while (getchar() != '\n');
			break;
		case 'q':
			return 0;
			break;
		}
		

	}
	return 0;
}
HashTable createHash(int size, float A) {
	HashTable H;
	int i;
	H = (struct HashTbl*)malloc(sizeof(struct HashTbl));
	H->TableSize = size;
	H->A = A;
	H->TheLists = (position*)malloc(sizeof(position)*size);

	for (i = 0; i < size; i++) {
		H->TheLists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
		H->TheLists[i]->Next = NULL;
	}
	return H;
}

position Find(int key, HashTable H) {
	position P;
	List L;
	L = H->TheLists[hx(key, H)];
	P = L->Next;

	while (P != NULL && P->Element != key)
		P = P->Next;

	return P;
}
position FindPrevious(int key, HashTable H) {
	position P;
	List L;
	L = H->TheLists[hx(key, H)];
	P = L;

	while (P->Next != NULL && P->Next->Element != key)
		P = P->Next;

	return P;
}
void Insert(int key, HashTable H) {
	position Pos, newcell;
	List L;
	Pos = Find(key, H);
	if (Pos == NULL) {
		newcell = (struct ListNode *)malloc(sizeof(struct ListNode));
		L = H->TheLists[hx(key, H)];
		newcell->Next = L->Next;
		newcell->Element = key;
		L->Next = newcell;
	}
}

void Delete(int key, HashTable H) {
	position Pos,tmp;
	Pos = FindPrevious(key, H);
	
	tmp = Pos->Next;
	Pos->Next = tmp->Next;
	free(tmp);
	

}

int hx(int key, HashTable H) {
	//float b;
	float x = key*H->A;
	float a = fmodf(x, 1);
	int b = H->TableSize * a;
	//printf("%d\n", b);
	//return ((H->TableSize)*(key*(int)(H->A))%1);
	return b;
}

void Print(HashTable H) {
	int i, j;
	position pos;
	for (i = 0; i < H->TableSize; i++) {
		printf("Hash[%d] : ",i);
		pos = H->TheLists[i];
		for (j = 0; pos->Next != NULL; pos=pos->Next) {
			printf("%d ", pos->Next->Element);
		}
		printf("\n");
	}
}