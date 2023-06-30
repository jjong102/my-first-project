// Topological sort


#include <stdio.h>
#define SZ 6 //vertex ������ 6��
// 2���� �迭�� ������ graph



void addDEdge(int _sv, int _ev, int g[][SZ]) { // 2���� �迭�� �������� ������ �迭 ������ ������ ��.
	g[_sv][_ev] = 1;
	return;
}

void initIndgree(int g[][SZ], int ideg[]) {
	// ��� edge�� �������鼭,
	// indegree �迭�� ä��������.
	for (int i = 0; i < SZ; i++) { //���� vertex
		for (int j = 0; j < SZ; j++) { // ���� vertex
			if (g[i][j] > 0) {
				ideg[j]++;
			}
		}
	}
}

// indegree ���̺��� indegree == zero��
// vertex ��ȣ�� ��ȯ�ϴ� �Լ�

int findZeroIndegreeVertex(int indeg[]) {
	for (int i = 0; i < SZ; i++) {
		if (indeg[i] == 0) {
			return i;
		}
	}

	return -1; //error case, topo_sort�� ��, �Ǵ�  cycle�� ���ؼ� topo_sort �Ұ���
}

void topo_sort(int g[][SZ], int indeg[]) {
	
	while (1) {
		int v = findZeroIndegreeVertex(indeg);
		if (v == -1) {
			return; // ��....
		}
		printf("%d  \n", v);
		indeg[v] = -1; // ���� ã�� ���Ŷ�..

		// v�� ���� ������ outdegree edge�� ��ǥ vertex���� 
		// indegree�� 1�� ����
		for (int i = 0; i < SZ; i++) {
			if (g[v][i] > 0) {
				indeg[i]--;
			}
		}

	}

}

int main(void) {
	int graph[SZ][SZ] = { 0, }; //��� edge�� ���� ���� �ʱ�ȭ
	
	// �� vertex�� indegree ������ ���� �迭
	int indegree[SZ] = { 0, };


	addDEdge(0, 1, graph);
	addDEdge(0, 2, graph);
	addDEdge(0, 3, graph);
	addDEdge(1, 4, graph);
	addDEdge(2, 4, graph);
	addDEdge(2, 5, graph);
	addDEdge(3, 5, graph);
	addDEdge(5, 2, graph);
	// indegree �迭�� �ʱ�ȭ �ϴ� �Լ�
	initIndgree(graph, indegree);
	
	// Topolgical sort �˰���
	topo_sort(graph, indegree);

	//initGraph();
	return 0;
}


//Dijkstra �˰���
//- �Ѱ�: ����� ����, ������ ��� �������� �ִ�
//
// 
//Floyd �˰���
//- ��� �� ������ �ִ� ���
// if (G[i][j] > G [i][k] + G[k][i]) {
//		G[i][j] = G[i][j] + G[k][j]
//}