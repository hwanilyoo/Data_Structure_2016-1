#include<stdio.h>
#include<stdlib.h>
/* Stack*/
/*
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
Stack CreateStack(void);
int IsEmpty(Stack S);
void Pop(Stack S);
void Push(int data, Stack S);
int Top(Stack S);
void MakeEmpty(Stack S);

struct Node {
	int data;
	PtrToNode Next;
};
int main() {
	Stack S = CreateStack();
	
	int data;
	char command;
	int condition = 1;
	int a, b,top;
	while (condition) {
		scanf("%c",&command);
		switch (command)
		{
		case 'i':
			scanf("%d",&a);
			Push(a, S);
			break;
		
		case 't':
			top = Top(S);
			printf("Top : %d\n",top);
			break;
		
		case 'd':
			Pop(S);
			break;
		
		case 'q':
			MakeEmpty(S);
			return 0;
		}

	}
	
}
int IsEmpty(Stack S) {
	int result;
	if (S->Next != NULL) {
		result = 0;
	}
	else {
		result = 1;
	}

	return result;
}

void Pop(Stack S) {
	PtrToNode firstCell;

	if (IsEmpty(S)) printf("Empty Stack");
	else {
		firstCell = S->Next;
		S->Next = S->Next->Next;
		free(firstCell);
	}
}

void Push(int data, Stack S) {
	PtrToNode TmpCell;
	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	
	if (TmpCell == NULL) {
		printf("Out of Space\n");
	}
	else {
		TmpCell->data = data;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

int Top(Stack S) {
	if (!IsEmpty(S))
		return S->Next->data;
	
	printf("Empty Stack\n");
	return 0;
}

void MakeEmpty(Stack S) {
	PtrToNode TmpCell;
	while (S->Next != NULL) {
		TmpCell = S;
		S = S->Next;
		free(TmpCell);
		
	}
	free(S);
}

Stack CreateStack(void) {
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	
	if (S == NULL) {
		printf("Out of Space");
	}
	S->Next = NULL;

	return S;
}
*/

struct QueueRecord {
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};
typedef struct QueueRecord *Queue;
void MakeEmpty(Queue Q);
void Enqueue(int x, Queue Q);
int IsEmpty(Queue Q);
static int Succ(int value, Queue Q);
Queue CreateQueue(int Capacity);
void PrintFront(Queue Q);
void PrintRear(Queue Q);
int IsFull(Queue Q);
void Dequeue(Queue Q);
int main() {

	int number;
	scanf("%d",&number); //queue�� ũ�� �Է�
	Queue Q = CreateQueue(number);
	char command;
	int condition = 1;
	int data,i;
	while (condition) {
		scanf("%c",&command);

		switch (command) {
			case 'e':
				scanf("%d",&data);
				Enqueue(data, Q);
				break;
			case 'd':
				Dequeue(Q);
				break;
			case 'f':
				PrintFront(Q);
				break;
			case 'r':
				PrintRear(Q);
				break;
			case 'q':
				for (i = 0; i < number; i++)
				{
					free(Q->Array[i]);
				}
				free(Q);
				break;
		}

	}
	return 0;
}

void MakeEmpty(Queue Q) {
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

void Enqueue(int x, Queue Q) {
	if (IsFull(Q)==1) {
		printf("Full Queue");
	}
	else {
		printf("%d�� ���ԉ���ϴ�.\n",x);
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = x;
	}
}

int IsEmpty(Queue Q) {
	return Q->Size == 0;
}

static int Succ(int value, Queue Q) {
	if (++value == Q->Capacity) {
		value = 0;
	}
	return value;
}

Queue CreateQueue(int Capacity) {
	Queue TmpCell = (Queue)malloc(sizeof(struct QueueRecord));
	if (TmpCell == NULL) {
		printf("Out of Space!!");
	}
	TmpCell->Array = (int*)malloc(sizeof(int)*Capacity);
	TmpCell->Size = 0;
	TmpCell->Front = 1;
	TmpCell->Rear = 0;
	TmpCell->Capacity = Capacity;
	printf("%d ũ���� Queue�� �����Ǿ����ϴ�.\n",Capacity);
	return TmpCell;
}

void PrintFront(Queue Q) { //ù��° �� ���
	if (IsEmpty(Q)) {
		printf("Queue�� ������ϴ�.\n");
	}
	else {
		printf("Queue�� First�� ���� %d�Դϴ�.\n",Q->Array[Q->Front]);
	}

}

void PrintRear(Queue Q) {
	if (IsEmpty(Q)) {
		printf("Queue�� ������ϴ�.\n");
	}
	else {
		printf("Queue�� Rear�� ���� %d�Դϴ�.\n", Q->Array[Q->Rear]);
	}
}

int IsFull(Queue Q) {
	int res;
	if (Q->Capacity == Q->Size) { //�� ���ִٸ�
		res = 1;
	}
	else {
		res = 0;
	}
}

void Dequeue(Queue Q) {
	if(IsEmpty(Q)) {
		printf("ť�� ������ϴ�.\n");
	}else{
		printf("ť�� 1ĭ ������ϴ�.\n");
		Q->Array[Q->Front++];
	}
}