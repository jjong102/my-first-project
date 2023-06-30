#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType{
	int n; // ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}Graphtype;

int visited[MAX_VERTICES];

void init(GraphType* g) { // �׷����� �ʱ�ȭ �ϴ� �Լ�
	int r, c;
	g->n = 0; // ������ ������ 0���� ����
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0; // �׷����� ������ �� 0���� ������ �ش�.
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ���� ���� �ʰ�"); 
		return;
	}
	g->n++;
}

void inser_dege(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE; //�ϴ� �湮 �ߴٰ� ǥ�� �ϰ�,
	printf("����  %d ->", v); // �� ���� �ִ´ٰ� �����.
	for (w = 0; w < g->n; w++) // ���� ��ȣ�� �ϳ��� Ȯ���ϸ鼭
		if (g->adj_mat[v][w] && !visited[w]) 
			dfs_mat(g, w);
}











int main(void) {


	return 0;
}