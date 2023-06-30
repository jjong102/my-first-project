#include <stdio.h>
#define MAP_SZ 10
#define SZ MAP_SZ*MAP_SZ

// Dijkstra ����ü
struct dij {
	int prev;   // ������ ������ ��ġ�°�
	int dist;   // �ִܰŸ�
	int done;   // �ִܰŸ� ã�Ҵ°�
};


// Dijkstra �˰����� ������ ���� ���̺�
struct dij dtable[SZ];

struct rc {
	int r;
	int c;
};

// 0�� �����
// 1�� ��
int map[MAP_SZ][MAP_SZ] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

// row�� col�� idx�� �ٲٴ� �Լ�
int rc2idx(int r, int c) {
	return (r * MAP_SZ + c);
}
// idx�� row�� col���� �ٲٴ� �Լ�
struct rc idx2rc(int idx) {
	struct rc temp = { idx / MAP_SZ, idx % MAP_SZ };
	return temp;
}

int graph[SZ][SZ];

// (r1, c1) ---> (r2, c2) : ���� �߰�
void addEdge(int r1, int c1, int r2, int c2) {
	int v1 = rc2idx(r1, c1);
	int v2 = rc2idx(r2, c2);
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

void initGraph() {

	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {

			if (map[i][j] == 1) { // ��
				continue; // �� ����
			}

			//----- ������
			// �����̰�, ���� �ƴϸ�, edge ���� (i,j) ---> (i, j+1)
			if ((j + 1) < MAP_SZ && map[i][j + 1] != 1) {
				addEdge(i, j, i, j + 1);
			}

			//------ �Ʒ���
			// �����̰�, ���� �ƴϸ�, edge ���� (i,j) ---> (i+1, j)
			if ((i + 1) < MAP_SZ && map[i + 1][j] != 1) {
				addEdge(i, j, i + 1, j);
			}
		}
	}
}

void printGraph() {

	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			printf("%d  ", graph[i][j]);
		}
		printf("\n");
	}
}

void initDTable(int _sidx) {
	for (int i = 0; i < SZ; i++) {

		if (i == _sidx) {  // �ڱ��ڽ�
			dtable[i].dist = 0;
			dtable[i].prev = _sidx;
			dtable[i].done = 1;
		}
		else if (graph[_sidx][i] > 0) {
			dtable[i].dist = graph[_sidx][i];
			dtable[i].prev = _sidx;
			dtable[i].done = 0;
		}
		else {
			dtable[i].dist = 99999999; // ���Ѵ�, ���� ����.
			dtable[i].prev = -1;
			dtable[i].done = 0;
		}

	}
}

int findMinDistVtx() {
	// dtable���� , �ִ� ��ΰ� �������� ���� �͵���, ���� ª�� �Ÿ�
	int minDis = 999;
	int minIdx = -1;
	for (int i = 0; i < SZ; i++) {
		if (dtable[i].done == 0 && dtable[i].dist < minDis) {
			minDis = dtable[i].dist;
			minIdx = i;
		}
	}
	return minIdx;
}

// (r1, c1) : �����
// (r2, c2) : ������
void do_dijkstra(int r1, int c1, int r2, int c2) {

	int sidx = rc2idx(r1, c1);  // Graph���� ���� index�� ��ȯ�Ѵ�.
	int tidx = rc2idx(r2, c2);

	initDTable(sidx);

	// dijkstra �˰��� ���� ����
	while (1) {

		// done == 0 �� �͵� �߿���, �Ÿ��� ���� ª�� ��
		int res = findMinDistVtx();

		dtable[res].done = 1;
		if (res == tidx) { // �������� ã������,
			break;
		}
		for (int i = 0; i < SZ; i++) {
			if (dtable[i].done == 0) {  // ���� �ִ� ��ΰ� �������� �ʾ�����,
				if (graph[res][i] > 0) {// res(��� �ִ� ��ΰ� ������ ��)���� �� �� �ִ� ���� ������,
					// res�� ���ؼ� ���� ����, ������ ���� �ִ� �溸�� ª����,
					if (dtable[i].dist > dtable[res].dist + graph[res][i]) {
						dtable[i].prev = res;
						dtable[i].dist = dtable[res].dist + graph[res][i];
					}
				}
			}
		}
	}
}

void printDTable() {

	printf("idx   prev   dist    done\n");
	for (int i = 0; i < SZ; i++) {
		printf("%d   %d   %d    %d\n", i, dtable[i].prev, dtable[i].dist, dtable[i].done);
	}
}

void printMap() {
	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {
			printf("%d  ", map[i][j]);
		}
		printf("\n");
	}
}

int main() {

	initGraph();
	//printGraph();

	int r1 = 5;
	int c1 = 5;

	int r2 = 9;
	int c2 = 9;

	do_dijkstra(r1, c1, r2, c2);

	//printDTable();

	// ��θ� ����� ����. (�������� ����� ����)
	int t = rc2idx(r2, c2);
	int s = rc2idx(r1, c1);

	int temp = t;
	while (1) {
		//printf("%d \n", temp);
		struct rc k = idx2rc(temp);
		map[k.r][k.c] = 8;
		temp = dtable[temp].prev;
		if (temp == s) {
			//printf("%d \n", temp);
			struct rc k = idx2rc(temp);
			map[k.r][k.c] = 8;
			break;
		}
	}

	printMap();



	return 0;
}