#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType{
	int n; // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}Graphtype;

int visited[MAX_VERTICES];

void init(GraphType* g) { // 그래프를 초기화 하는 함수
	int r, c;
	g->n = 0; // 정점의 개수를 0으로 설정
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0; // 그래프의 값들을 다 0으로 설정해 준다.
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점 개수 초과"); 
		return;
	}
	g->n++;
}

void inser_dege(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE; //일단 방문 했다고 표시 하고,
	printf("정점  %d ->", v); // 이 값을 넣는다고 출력함.
	for (w = 0; w < g->n; w++) // 정점 번호를 하나씩 확인하면서
		if (g->adj_mat[v][w] && !visited[w]) 
			dfs_mat(g, w);
}











int main(void) {


	return 0;
}