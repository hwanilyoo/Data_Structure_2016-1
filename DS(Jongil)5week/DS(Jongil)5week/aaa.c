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
	scanf("%d",&number); //queue의 크기 입력
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
		printf("%d가 삽입됬습니다.\n",x);
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
	printf("%d 크기의 Queue가 생성되었습니다.\n",Capacity);
	return TmpCell;
}

void PrintFront(Queue Q) { //첫번째 값 출력
	if (IsEmpty(Q)) {
		printf("Queue가 비었습니다.\n");
	}
	else {
		printf("Queue의 First의 값은 %d입니다.\n",Q->Array[Q->Front]);
	}

}

void PrintRear(Queue Q) {
	if (IsEmpty(Q)) {
		printf("Queue가 비었습니다.\n");
	}
	else {
		printf("Queue의 Rear의 값은 %d입니다.\n", Q->Array[Q->Rear]);
	}
}

int IsFull(Queue Q) {
	int res;
	if (Q->Capacity == Q->Size) { //꽉 차있다면
		res = 1;
	}
	else {
		res = 0;
	}
}

void Dequeue(Queue Q) {
	if(IsEmpty(Q)) {
		printf("큐가 비었습니다.\n");
	}else{
		printf("큐를 1칸 비웠습니다.\n");
		Q->Array[Q->Front++];
	}
}