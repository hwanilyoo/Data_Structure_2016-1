#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
	int studentID;
	char studentName[30];
	struct Node* Next;
	struct Node* Prev;

};

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
void insert(int studentID, char *studentName, Position P);
Position Find(int x, List L);
Position Find2(int x, List L);
void Delete(int x, List L);
void PrintList(List L);
void DeleteList(List L);

int main() {
	char * name = (char *)malloc(sizeof(char) * 30);
	List L;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	int condition = 1;
	char command;
	int studentid;
	Position pos;

	while (condition) {
		scanf("%c", &command);
		switch (command) {

		case 'i':
			scanf("%d", &studentid);
			scanf("%s", name);
			pos = Find(studentid, L);
			insert(studentid, name, pos);
			while (getchar() != '\n');

			break;

		case 'd':
			scanf("%d", &studentid);
			Delete(studentid, L);
			break;

		case 'p':
			PrintList(L);
			break;


		case 'q':
			DeleteList(L);
			return 0;
			


		}



	}
	
}

void insert(int studentID, char *studentName, Position P) {

	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL) {
		printf("Out of Space\n");
	}

	TmpCell->studentID = studentID;
	strcpy(TmpCell->studentName, studentName);
		
		if (P->Next != NULL) {
			TmpCell->Prev = P;
			TmpCell->Next = P->Next;
			TmpCell->Next->Prev = TmpCell;
			P->Next = TmpCell;
			
			
		}
		else {
			TmpCell->Prev = P;
			TmpCell->Prev->Next = TmpCell;
			
			TmpCell->Next = NULL;

		}
}
Position Find(int x, List L) {
	Position P;
	P = L;

	while (P->Next != NULL && P->Next->studentID < x)
		P = P->Next;

	
	return P;

}

Position Find2(int x, List L) {
	Position P;
	P = L->Next;

	while (P != NULL && P->studentID != x)
		P = P->Next;

	return P;

}

void Delete(int x, List L) { 
	Position P;
	P = Find2(x, L);

	P->Prev->Next = P->Next;
	P->Next->Prev = P->Prev;
	free(P);
}

void PrintList(List L) {
	Position P = L;
	while (P->Next!=NULL) {
		printf("Student ID : %d, Name : %s\n", P->Next->studentID, P->Next->studentName);
		P = P->Next;
	}

}

void DeleteList(List L) {
	Position TmpCell;
	TmpCell = L;
	while (L->Next != NULL) {
		TmpCell = L;
		L = L->Next;
		free(TmpCell);
		
	}
	free(L);
	
}