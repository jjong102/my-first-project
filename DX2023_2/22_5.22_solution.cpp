#include <stdio.h>
#define MAP_SZ 5
#define SZ MAP_SZ*MAP_SZ

typedef struct dij {
	int dist;
	int prev;
	int done;
}dij;

typedef struct rc {
	int r;
	int c;
}rc;

dij dtable[SZ];
int graph[SZ][SZ];

int map[MAP_SZ][MAP_SZ] = {
	{0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0}
};

int rc2idx(int r, int c) {
	return (r * MAP_SZ + c);
}

rc idx2rc(int idx) {
	rc res = { idx / MAP_SZ , idx % MAP_SZ };
	return res;
}


void addEdge(int r1, int c1, int r2, int c2) {
	int v1 = rc2idx(r1, c1);
	int v2 = rc2idx(r2, c2);
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}


void initGraph() {
	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {
			if (map[i][j] == 1) {
				continue;
			}

			if ((j + 1) < MAP_SZ && map[i][j + 1] != 1) {
				addEdge(i, j, i, j + 1);
			}

			if ((i + 1) < MAP_SZ && map[i + 1][j] != 1) {
					addEdge(i, j, i + 1, j);
			}
		}
	}
}

void initDTable(int _sidx) {
	for (int i = 0; i < SZ; i++) {
		if (i == _sidx) {
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
			dtable[i].dist = 9999999;
			dtable[i].prev = -1;
			dtable[i].done = 0;
		}
	}
}


int findMinDistVrt() {
	int Mindis = 999;
	int Minidx = -1;
	for (int i = 0; i < SZ; i++) {
		if (dtable[i].done == 0 && dtable[i].dist < Mindis) {
			Mindis = dtable[i].dist;
			Minidx = i;
		}
	}
	return Minidx;
}


void do_dijkstra(int r1, int c1, int r2, int c2) {
	int sidx = rc2idx(r1, c1);
	int tidx = rc2idx(r2, c2);

	initDTable(sidx);

	while (1) {
		int res = findMinDistVrt();

		dtable[res].done = 1;
		if (tidx == res) {
			break;
		}

		for (int i = 0; i < SZ; i++) {
			if (dtable[i].done == 0) {
				if (graph[res][i] > 0) {// 길이 있어야지! , 길이 있어야지!
					if (dtable[i].dist > dtable[res].dist + graph[res][i]) {
						dtable[i].dist = dtable[res].dist + graph[res][i];
						dtable[i].prev = res;
					}
				}
			}
		}


	}
}


void printMap() {
	for (int i = 0; i < MAP_SZ; i++) {
		for (int j = 0; j < MAP_SZ; j++) {
			if (map[i][j] == 1) {
				printf("%c   ", '#');
			}
			else if (map[i][j] == 8) {
				printf("%c   ", '*');
			}
			else {
				printf("%c  ", '.');
			}
		}
		printf("\n");
	}
}




int main(void) {
	initGraph();

	int r1 = 0;
	int c1 = 4;
	int r2 = 4;
	int c2 = 0;

	do_dijkstra(r1, c1, r2, c2);

	int tidx = rc2idx(r2, c2);
	int sidx = rc2idx(r1, c1);

	int temp = tidx;
	while (1) {
		rc k = idx2rc(temp);
		map[k.r][k.c] = 8;
		temp = dtable[temp].prev;
		if (sidx == temp) {
			rc k = idx2rc(temp);
			map[k.r][k.c] = 8;
			break;
		}
	}

	printMap();
	return 0;
}


