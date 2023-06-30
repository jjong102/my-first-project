// Dijsktra Algorithm
// 
// 
// 0. �ʱ�ȭ �Ѵ�.
//	-prev ������ ������ ���ƴ°�
//	-dist �ִ� �Ÿ�
//	-done �ִ� ��θ� ã�Ҵ°�
// 1. v = ���� vertex
// 2. v�� ���� �� �� �ִ� ���ο� ��� update
// 3. v <= final = 0�� vertex�� �߿� 
//	  dist�� ���� ª�� �� v[final] = 1

#include <stdio.h>
#define G_SZ 7

typedef struct {
	int prev; //������ ��ģ vertex ��ȣ
	int dist; // start vertex --> ���������� �Ÿ�.
	int done; // �ִ� �Ÿ��� ã�Ҵ°�? 1:yes, 0: no
}DijkstraElement;

void initDTable(DijkstraElement dtable[]) {
	for (int i = 0; i < G_SZ; i++) {
		dtable[i].prev = -1;
		dtable[i].dist = 99999;
		dtable[i].done = 0;
	}
}

// dtable���� dist�� ���� ª��, done = 0 vertex�� ã�Ƽ�,
// �� ��ȣ�� ��ȯ
// ����, ��� vertex���� done = 1�̸�, -1�� ��ȯ == >Dijkstra �˰����� ���Ḧ �ǹ�
int find_shortest_path_vertex(DijkstraElement dtable[]) {

	int vertex_idx = -1; //�ִ� �Ÿ��� �����Ǵ� vertex ��ȣ
	int vertex_dist = 9999; //�� vertex�� �ִܰŸ�

	for (int i = 0; i < G_SZ; i++) {
		if (dtable[i].done == 0 && dtable[i].dist < vertex_dist) {
			vertex_idx = i;
			vertex_dist = dtable[i].dist;
		}
	}
	return vertex_idx;
}

void showDTable(DijkstraElement dtable[]) {
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", i);
	}
	printf("\n");

	//prev
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", dtable[i].prev);
	}
	printf("------prev\n");
	//dist
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", dtable[i].dist);
	}
	printf("------dist\n");
	//done
	for (int i = 1; i < G_SZ; i++) {
		printf("%5d ", dtable[i].done);
	}
	printf("------done\n");
}

// s : start vertex ��ȣ
// e : end vertex ��ȣ
// s ---> e���� ���� ��θ� (�߰� vertex�����ؼ�) �����ش�.
void showPath(int s, int e, DijkstraElement dtable[]) {

	int current = e;
	while (current != s) {
		printf("%d\n", current);
		current = dtable[current].prev;
	}
	printf("%\n", s);

}

int main(void) {

	DijkstraElement dtable[G_SZ];
	int graph[G_SZ][G_SZ] = {
		{-1,-1,-1,-1,-1,-1,-1},
		{-1,-1, 3,-1,15,-1,-1},
		{-1, 3,-1,30, 2,-1,-1},
		{-1,-1,30,-1,-1, 3, 4},
		{-1,15, 2,-1,-1, 1,-1},
		{-1,-1,-1, 3, 1,-1,20},
		{-1,-1,-1, 4,-1,20,-1}
	};
	//dtable �ʱ�ȭ
	initDTable(dtable);

	//start vertex = 1
	//start vertex���� ���� ������ �� �ִ� vertex�鿡 ���ؼ�
	//dtable�� �����Ѵ�.
	int start_vertex = 1;
	dtable[start_vertex].done = 1;

	for (int i = 0; i < G_SZ; i++) {
		if (graph[start_vertex][i] != -1) { // start_vertex --->i���� ���� ���� ���� ������, 
			dtable[i].dist = graph[start_vertex][i];
			dtable[i].prev = start_vertex;
		}
	}

	while (1) {
		int v = find_shortest_path_vertex(dtable);
		if (v == -1) { // dijkstra �˰��� �Ϸ�
			break;
		}
		//v�� ���ؼ� ���ŵǴ� ��ΰ� �� ���� vertex���� ã�Ƽ�,
		//�ش� dtable�� ����

		dtable[v].done = 1; // v������ �ִ� ��ΰ� �����Ǿ���.

		// �ִ� ��ΰ� ������ ���� ���ؼ� ���� ã�Ƴ�����.
		for (int i = 0; i < G_SZ; i++) {
			// dtable���� ���� ª�� �Ÿ��� ���� vertex�̸鼭, done = 0�� vertex�� ã�´�.
			if (graph[v][i] > -1 && dtable[i].done == 0) {
				// i���� �ִܰ�ΰ� �������� ���� �͵� �߿���...
				// v�� ���ؼ� i���� ���� ���� ���� �˷��� �ͺ��� �� ª���鼭

				// �̹� �˷��� �Ÿ� > v�� ���ؼ� ���� ��
				if (dtable[i].dist > dtable[v].dist + graph[v][i]) {
					dtable[i].dist = dtable[v].dist + graph[v][i];
					dtable[i].prev = v;
				}
			}
		}
	}

	showDTable(dtable);
	printf("------------------\n");
	showPath(1, 6, dtable);

	return 0;
}