#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ListNode *position;
typedef position List;
typedef struct GraphTbl *GraphTable;
void Insert(GraphTable G, int a, int b);
GraphTable createGraph(int size);
void dfs(GraphTable G, int v);

struct ListNode {
	int Element;
	position Next;
};

struct GraphTbl {
	int TableSize;
	List* TheLists;
};

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
int PrintFront(Queue Q);
void PrintRear(Queue Q);
int IsFull(Queue Q);
void Dequeue(Queue Q);
int *visited;
void bfs(GraphTable G, int v);
#define true 1
#define false 0
int main() {
	
	GraphTable G = createGraph(10);
	Insert(G, 6, 7);
	Insert(G, 5, 7);
	Insert(G, 4, 7);
	Insert(G, 3, 7);
	Insert(G, 2, 6);
	Insert(G, 1, 4);
	Insert(G, 2, 5);
	Insert(G, 1, 3);
	Insert(G, 0, 2);
	Insert(G, 0, 1);
	Insert(G, 0, 100);
	//printf("%d\n",G->TheLists[0]->Next->Element);
	printf("%d\n", G);
	printf("%d\n", G->TheLists);
	//printf("%d\n", G->TheLists[0]->Next);
	
	/*dfs(G, 0);
	printf("\n");
	memset(visited, 0, sizeof(visited)*10);
	bfs(G, 0);
	printf("\n");*/
	return 0;
}

GraphTable createGraph(int size) {
	GraphTable G;
	G = (struct GraphTbl*)malloc(sizeof(struct GraphTbl));
	G->TableSize = size;
	G->TheLists = (position*)malloc(sizeof(position)*size);

	for (int i = 0; i < size; i++) {
		G->TheLists[i] = NULL;
	}

	visited = (int*)malloc(sizeof(int)*size);
	return G;
}

void dfs(GraphTable G, int v) {
	List w;
	visited[v] = true;
	printf("%5d ", v);
	for (w = G->TheLists[v]; w; w = w->Next) {
		if (visited[w->Element]!=1) {
			dfs(G,w->Element);
		}
	}
}

void bfs(GraphTable G, int v) {
	List w;
	Queue Q = CreateQueue(100);
	printf("%5d ",v);
	visited[v] = true;
	
	Enqueue(v, Q);
	
	while (IsEmpty(Q)==0) {
		v = PrintFront(Q);
		Dequeue(Q);
		
		for (w = G->TheLists[v]; w; w = w->Next) {
			if (visited[w->Element] != 1) {
				printf("%5d ",w->Element);
				visited[w->Element] = true;
				Enqueue(w->Element, Q);
			}
		}
	}
}
void Insert(GraphTable G, int a, int b) {
	if (b == 100) {
		G->TheLists[0]->Next->Element = 300;
		return;
	}
	
	position tmp, tmp1, pos, pos1;
	tmp = (position)malloc(sizeof(struct ListNode));
	tmp->Element = b;
	tmp->Next = NULL;

	tmp1 = (position)malloc(sizeof(struct ListNode));
	tmp1->Element = a;
	tmp1->Next = NULL;

	if (G->TheLists[a] == NULL) {
		G->TheLists[a] = tmp;
	}
	else {
		pos = G->TheLists[a];
		G->TheLists[a] = tmp;
		tmp->Next = pos;
	}

	if (G->TheLists[b] == NULL) {
		G->TheLists[b] = tmp1;
	}
	else {
		pos1 = G->TheLists[b];
		G->TheLists[b] = tmp1;
		tmp1->Next = pos1;
	}
	

}


void MakeEmpty(Queue Q) {
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

void Enqueue(int x, Queue Q) {
	if (IsFull(Q) == 1) {
		//printf("Full Queue");
	}
	else {
		//printf("%d가 삽입됬습니다.\n", x);
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
	//printf("%d 크기의 Queue가 생성되었습니다.\n", Capacity);
	return TmpCell;
}

int PrintFront(Queue Q) { //첫번째 값 출력
	if (IsEmpty(Q)) {
		//printf("Queue가 비었습니다.\n");
		return -1;
	}
	else {
		//printf("Queue의 First의 값은 %d입니다.\n", Q->Array[Q->Front]);
		return Q->Array[Q->Front];
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
	if (IsEmpty(Q)) {
		printf("큐가 비었습니다.\n");
	}
	else {
		//printf("큐를 1칸 비웠습니다.\n");
		Q->Array[Q->Front++];
		Q->Size--;
	}
}

