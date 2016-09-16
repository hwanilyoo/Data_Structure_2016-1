#include<stdio.h>

#define INF 987654321 //���Ѵ�(������°��)
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 23 //������ ��
#define INT_MAX 1111111 //�ִ�����

int weight[MAX_VERTICES][MAX_VERTICES] = { //�������
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

int distance[MAX_VERTICES]; /*�����������κ����� �ִܰŸ�*/
int found[MAX_VERTICES]; /*�湮�� ���� ǥ��*/
int prev[MAX_VERTICES]; /*���� ���*/
int rev[MAX_VERTICES]; /*���� prev�迭�� �̿��ؼ� ��������� ���������� ������ ������ ���� ����ϱ� ���� �迭*/
int choose(int distance[], int n, int found[]);
void dijkstra(int start, int n);

int main() {
	int start;
	int end,i;
	int temp;
	int len=0;
	
	printf("������� �Է��ϼ��� (�Է��� %d ����) : ",MAX_VERTICES-1);
	scanf("%d", &start);
	printf("�������� �Է��ϼ��� (�Է��� %d ����) : ",MAX_VERTICES-1);
	scanf("%d", &end);
	

	dijkstra(start, MAX_VERTICES);
	
	/*���*/
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


	printf("��� : ");
	for (i = len - 1; i >= 0; i--) {
		printf("%d ", rev[i]);
		if (i == 0)break;
		printf("-> ");
	}
	printf("\n");
	printf("�� ��� : %d\n", distance[end]);
	
	return 0;
}


int choose(int distance[], int n, int found[]) {/*found�� �� �ִܰ�θ� ã�Ƴ��� �Լ�.*/
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
		distance[i] = weight[start][i]; /*���� vertex�� ����Ǿ� �ִ°��� weight���� �ְ� �������� INF�� ä��.*/
		if (weight[start][i] != INF) {
			prev[i] = start; /*��� ���� ����Ǿ��ִ� ���� prev�迭�� �������� ��ȣ�� ���.*/
		}
		found[i] = FALSE; /*ó�� set��(found�迭) �ִܰŸ� �߰��Ѱ� �����ϱ� ���� FALSE�� ����.*/
	}
	found[start] = TRUE; /*start�� �ڱ��ڽ� �Ÿ��� 0 �̹Ƿ� TRUE�� ����� found�迭�� ���.*/
	distance[start] = 0; /*�ڱ��ڽ��� �Ÿ��� 0*/

	for (i = 0; i < n - 1; i++) {
		u = choose(distance, n, found); /*choose�Լ��� �̿��ؼ� u�� ��´�. ��, ������� ����� ��� �� ���� weight���� ���� ��带 ����.*/
		found[u] = TRUE; /*u�� �ִܰŸ��̱� ������ found�迭 set�� ���.*/
		for (w = 0; w < n; w++) {
			if (!found[w]) { /*w�� �̹� ����� ���� set�� �������� ������ �����Ѵ�. �̹� set�� ������ �ִܰŸ� ã���Ŵϱ� �������� ����.*/
				if (distance[u] + weight[u][w] < distance[w]) {
					distance[w] = distance[u] + weight[u][w];
					prev[w] = u; /*���� ������ ������ݴϴ�.*/
				}
			}
		}
	}


}

