// spanning tree, ���� Ʈ��
// - ��� vertex���� ����� subgraph

// minimum spanning tree, �ּҽ���Ʈ��
// - �ּ����� edge������ ��� vertex�� �����ϴ� spanning tree
// - vertex���� - 1�� �ּ� edge����
// - ����, weighted �׷������ �ϸ�, MST�� weight�� ���� �ּ�

// MST�� ����
// - �ּ� ������� ���� �Ǽ�
// - �ּ� ������� ��Ʈ��ũ�� �Ǽ�

// MST �˰���
// - Prim Algorithm
//	- Ư¡: vertex ����
//		1. ���� vertex�� ���Ѵ�.
//		2. ���� vertex�� '����'�Ǿ��ٰ� ǥ���Ѵ�.
//		3. ���� vertex���� ������ vertex�� ����� edge�߿� ���� ���� weight�� �۴� edge�� ã�´�.
//		4. edge�� ����� ������ vertex�� ���ԵǾ��ٰ� ǥ���Ѵ�.
//		5. 3������ �ݺ��ϴµ�, n-1����  edge�� ���õ� ������.... (n�� vertex�� ����)
//		O(n^2)
// 
// - Kruska Algorithm
//	- Prim Algorithm ���ٴ� ���� O(E log E), ������ �� ��������� �Ѵ�. (������ ������)
//	- Ư¡: edge ����
//	���̵��: ���� ���� weight�� ���� edge�� ã�Ƽ� ������� �߰�, �ٸ� edge �߰��� ���ؼ� cycle�� �� �����쿡�� �߰�
//		1. ���� ���� weight�� ������ edge�� �����Ѵ�.
//			v1 - edge - v2
//		2. v1�� v2�� family���� �˻��ؼ�, -------> union-find
//			- family�� �ƴϸ�, edge�� MST�� �߰��ϰ�
//			- v1�� v2�� ��ȥ���Ѽ� family�� �����.
//		3. 1������ �ݺ�, n-1���� edge�� ���õ� ������.
//	
//  - Kruska Algorithm�� ���� ���� ��� ã��
//		- family tree 
//			A B C D E F G H
//			0 1 2 3 4 5 6 7
//			0 1 2 3 4 5 0 7 (<- A�� G�� ��ȥ �� ��� [���� ������ ������ ������.])
//			0 1 2 3 4 2 0 0 (<- A-G-H�� family�� �ǰ�, C-F�� family�� �Ǿ�����)
//			0 1 0 3 4 0 0 0 (<- A-G-H-C-F�� family�� �Ǿ�����)
//
// 
// 
// Graph �˰����� �� Dijkstra �˰���, �ִܰ��ã�� �˰���
// 
// �׺���̼�
// ���ӿ��� ���� �̵�
// 
// Dijstra algorithm -> A* Algorithm 
//
// 
// Dijstra algorithm : Ư�� ��������� �ٸ� ��� ���������� �ִ� �Ÿ�
//		 
// prev: ���� ������ ������ �湮�ߴ°�..
// dist: ���������� ���� �������� �Ÿ�
// final: �ִ� �Ÿ��� �˷��� �ֳ� �ƴϳ�?
// 
// 
//		 A  B   C   D   E
// prev  A -1  -1  -1  -1
// dist  0 999 999 999 999
// final 1  0   0   0   0

//		 A  B   C   D   E
// prev  A  A  -1  -1  -1
// dist  0  1  999 999 999
// final 1  1   0   0   0

//		 A  B   C   D   E
// prev  A  A   A  -1  -1
// dist  0  1   1 999 999
// final 1  1   1   0   0

//		 A  B   C   D   E
// prev  A  A   A   C  -1
// dist  0  1   1   2 999
// final 1  1   1   1   0

//		 A  B   C   D   E
// prev  A  A   A   C   B
// dist  0  1   1   2   2
// final 1  1   1   1   1


#include <stdio.h>
#define NV 5

// - Prim Algorithm
void addEdge(int graph[][NV], int v1, int v2, int weight) {
	graph[v1][v2] = weight;
	graph[v2][v1] = weight;
}

// graph :
// sVertex : start vertex

void perform_MST_Prim(int graph[][NV], int sVertex) {
	// visited way
	int visited[NV] = { 0, }; //MST�� �����ϴ� vertex�� ���ԵǾ������� ǥ��. 1����, 0������

	visited[sVertex] = 1; // start vertex�� MST�� ���ԵǾ��ٰ� ǥ��...

	// ã�ƾ� �Ǵ� edge ���� : NV-1
	for (int i = 0; i < NV - 1; i++) { // NV-1���Ǥ� edge�� ã�´�.

		int minDist = 99999;
		int visted_vertex = -1;
		int nonvisited_Vertex = -1;

		//visited --> non-visited,, ���� ���� weight�� ���� ���� ã�´�.
		for (int j = 0; j < NV; j++) {
			//visited�� ã�´�.
			if (visited[j] == 1) {

				for (int k = 0; k < NV; k++) {
					if (visited[k] == 0) { // �湮���� ���� �ֵ� �߿���..... j ----> k
						if ((graph[j][k] > 0)&& graph[j][k] < minDist) { // j -->k edge�� �ְ�, ���ݱ��� �˷��� weight���� ������.

							minDist = graph[j][k];
							visted_vertex = j;
							nonvisited_Vertex = k;
						}

					}
				}
			}
		}

		//MST�� ���Ӱ� �߰��� edge�� ���
		printf("%d --- %d\n", visted_vertex, nonvisited_Vertex);
		visited[nonvisited_Vertex] = 1;

	}
}

void perform_MST_Kruskal(int graph[][NV]) {

	int family[NV] = { 0 ,1 ,2 ,3,4 };

	// NV-1 ���� ��ŭ�� edge�� ã�´�.
	for (int cnt = 0; cnt < NV - 1; cnt++) {

		int v1 = -1;
		int v2 = -1;
		int minDist = 9999999;
		// ���� weight�� ���� edge�� ã�Ƽ�, MST�� ���Խ�Ų��.
		for (int i = 0; i < NV; i++) {
			for (int j = i + 1; j < NV; j++) {
				
				//1. ��ΰ� �ְ�
				//2. ���� family�� �ƴϰ�,
				//3. ���ݱ��� �˷��� minDist���� ª�� edge��...
				if (graph[i][j] > 0 && family[i] != family[j] && minDist > graph[i][j]) {
					minDist = graph[i][j];
					v1 = i;
					v2 = j;
				}
			}
		}

		// ���� ª�� edge�� ã�����Ƿ�...
		printf("%d --- %d\n", v1, v2);
		//��ȥ�� ����... v1�� v2 ������ ��ȥ ����  ==>  cycle ������ ���ؼ�
		int old_family = family[v2];
		int new_family = family[v1];
		for (int k = 0; k < NV; k++) {
			if (family[k] == old_family) {
				family[k] = new_family;
			}
		}
	}
}

int main(void) {

	int graph[NV][NV];

	addEdge(graph, 0, 1, 100); // 0 ---> 1 dege, weight = 100
	addEdge(graph, 0, 2, 10);
	addEdge(graph, 1, 2, 40);
	addEdge(graph, 1, 3, 50);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 4, 10);

	//MST by Prim
	//perform_MST_Prim(graph, 0); // graph�� ���ؼ�, strat vertex = 0�� �Ͽ� MST�� Prim�˰������� ã�´�.


	//MST bty Kruskal
	perform_MST_Kruskal(graph);
	return 0;
}