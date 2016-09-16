#include<stdio.h>

#define INF 987654321 //무한대(연결없는경우)
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 23 //정점의 수
#define INT_MAX 1111111 //최대정수

int weight[MAX_VERTICES][MAX_VERTICES] = { //인접행렬
	{0, 2, INF, INF, INF, 10, INF, INF, 5, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
	{2, 0, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, 3, 0, INF, 8, INF, INF, INF, INF, INF, 4, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, 0, 3, 3, INF, 10, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, 8, 3, 0, INF, 6, INF, 10, INF, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, 3, INF, 0, 2, 1, INF, INF, INF, INF, 25, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, INF, 6, 2, 0, INF, INF, INF, 17, INF, 4, INF, INF, 28, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, 10, INF, 1, INF, 0, INF, 2, INF, 2, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{5, INF, INF, 3, 10, INF, INF, INF, 0, 6, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{4, INF, INF, INF, INF, INF, INF, 2, 6, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, 4, INF, 5, INF, 17, INF, INF, INF, 0, INF, INF, INF, INF, INF, 10, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, INF, INF, INF, INF, 2, INF, INF, INF, 0, 4, 5, INF, INF, INF, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, INF, INF, 25, 4, INF, INF, INF, INF, 4, 0, INF, INF, INF, INF, 3, INF, INF, INF, INF, INF },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, 0, INF, INF, INF, INF, 11, INF, INF, INF, INF },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 6, 4, INF, INF, 5, INF, INF, INF },
	{INF, INF, INF, INF, INF, INF, 28, INF, INF, INF, INF, INF, INF, INF, 6, 0, 5, INF, INF, INF, INF, INF, 3 },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 10, INF, INF, INF, 4, 5, 0, INF, INF, INF, INF, INF, INF },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, INF, INF, INF, 0, 7, INF, INF, 19, 1 },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 11, INF, INF, INF, 7, 0, INF, INF, 4, INF },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, INF, INF, INF, INF, 0, 28, INF, 7 },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 28, 0, 26, INF },
	{INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 19, 4, INF, 26, 0, INF },
	{ INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 3, INF, 1, INF, 7, INF, INF, 0 }
};

int distance[MAX_VERTICES]; /*시작정점으로부터의 최단거리*/
int found[MAX_VERTICES]; /*방문한 정점 표시*/
int prev[MAX_VERTICES]; /*이전 경로*/
int rev[MAX_VERTICES]; /*위의 prev배열을 이용해서 출발점에서 도착점까지 지나간 정점만 따로 기록하기 위한 배열*/
int choose(int distance[], int n, int found[]);
void dijkstra(int start, int n);

int main() {
	int start;
	int end,i;
	int temp;
	int len=0;
	
	printf("출발지를 입력하세요 (입력은 %d 이하) : ",MAX_VERTICES-1);
	scanf("%d", &start);
	printf("도착지를 입력하세요 (입력은 %d 이하) : ",MAX_VERTICES-1);
	scanf("%d", &end);
	

	dijkstra(start, MAX_VERTICES);
	
	/*출력*/
	temp = end; 
	rev[0] = end;
	for (i = 1; i < MAX_VERTICES; i++) {
		rev[i] = prev[temp];
		temp = prev[temp];
		if (temp == start) { 
			break;
		}
	}
	len = i + 1;


	printf("경로 : ");
	for (i = len - 1; i >= 0; i--) {
		printf("%d ", rev[i]);
		if (i == 0)break;
		printf("-> ");
	}
	printf("\n");
	printf("총 비용 : %d\n", distance[end]);
	
	return 0;
}


int choose(int distance[], int n, int found[]) {/*found에 들어갈 최단경로를 찾아내는 함수.*/
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i< n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}

	return minpos;
}


void dijkstra(int start, int n) {
	int i, u, w;
	for (i = 0; i < n; i++) {
		distance[i] = weight[start][i]; /*시작 vertex에 연결되어 있는곳은 weight값을 넣고 나머지는 INF로 채움.*/
		if (weight[start][i] != INF) {
			prev[i] = start; /*출발 점과 연결되어있는 점을 prev배열에 시작점의 번호를 기록.*/
		}
		found[i] = FALSE; /*처음 set은(found배열) 최단거리 발견한게 없으니깐 전부 FALSE로 만듬.*/
	}
	found[start] = TRUE; /*start는 자기자신 거리가 0 이므로 TRUE로 만들어 found배열에 기록.*/
	distance[start] = 0; /*자기자신은 거리가 0*/

	for (i = 0; i < n - 1; i++) {
		u = choose(distance, n, found); /*choose함수를 이용해서 u를 얻는다. 즉, 출발점과 연결된 노드 중 가장 weight값이 작은 노드를 선택.*/
		found[u] = TRUE; /*u는 최단거리이기 때문에 found배열 set에 기록.*/
		for (w = 0; w < n; w++) {
			if (!found[w]) { /*w가 이미 결과값 나온 set에 존재하지 않을때 실행한다. 이미 set에 있으면 최단거리 찾은거니깐 실행하지 않음.*/
				if (distance[u] + weight[u][w] < distance[w]) {
					distance[w] = distance[u] + weight[u][w];
					prev[w] = u; /*이전 정점을 기록해줍니다.*/
				}
			}
		}
	}


}

