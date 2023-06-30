//----------------------------------------------
// graph
// �׷����� (V,E) �� ǥ��
//	���� (vertex)
//	���� (edge)
// 
// �׷����� ����
//	undirected graph : ������ �׷���
//	directed graph : ���� �׷���
//	weighted graph :  ����ġ �׷���
//		������ ����̳� ����ġ�� �Ҵ�� �׷���
//		��Ʈ��ũ��� ��.
// 
// graph ǥ���� ��
//	adjacent vertex : ������ ���� ���� ����� ����
//	degree : �ϳ��� ������ ����� �ٸ� �׷����� ��
// 
// path
//	������ �׷����� ���� s�� ���� ���� e������ ���
// length
//	��� ���� �Դ���!
//	 simple 
//		��� �߿��� �ݺ��Ǵ� ������ ���� ���
//	 cycle
//		���� ������ ���� ������ ������ ���
// 
//	connected graph
//	tree
//  complete graph 
//		��� ������ ����Ǿ� �ִ� �׷���
// 
// �׷��� ǥ�� ��� 1.
//	2���� ����� �̿��ؼ� �׷����� ǥ��
//		��. �������̴�.
//		��. �޸𸮰� �����ϰ� ���� ���. (�Ÿ� ȿ���� ��)
// 
// �׷��� ǥ�� ��� 2.
//	SLL�� ǥ��
//----------------------------------------------


#include <stdio.h>
#include <stdlib.h>

#define NUM_VTX 6

struct node {
	int vtx;
	struct node* next;
};


struct node* graph[NUM_VTX]; 




//int graph[NUM_VTX][NUM_VTX];
//
//void addEdge(int v1, int v2) {
//
//	graph[v1][v2] = 1;
//	graph[v2][v1] = 1;
//	return;
//}
//
//
//int isThereEdge(int v1, int v2) {
//	return graph[v1][v2];
//}

void _addEdge(int v1, int v2) { // v1  -->  v2

	// v2�� ���� node�� �����.
	struct node* _v2 = (struct node*)malloc(sizeof(struct node));
	_v2->vtx = v2;
	_v2->next = 0;

	struct node* cur = graph[v1];

	if (cur == 0) {
		graph[v1] = _v2;// �� �����ʹ� ���� �޸𸮰� �Ҵ�Ǿ� �ִ� ���°� �ƴϱ� ������
						// null pointer�� ����Ű�� pointer�� ���� �ٲ㵵 ���� �ٲ��� �ʾƿ�!
		
		return;
	}

	else {
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = _v2;
		return;
	}
}
void addEdge(int v1, int v2) { // v1--> v2, v2--> v1
	

	// v1 --> v2
	_addEdge(v1, v2);
	
	// v2 --> v1
	_addEdge(v2, v1);


}
int isThereEdge(int v1, int v2) {
	struct node* cur = graph[v1];

	while (cur != 0) {
		if (cur->vtx == v2) {
			return 1;
		}
		else {
			cur = cur->next;
		}
	}
	return 0;
}


// �׷��� Ž�� �˰����� �̿��ؼ� 
	// DFS: depth first search -> stack
	// BFS: breadth first search -> queue
	// ���� : Ư�� vertex���� �� �� �ִ�, ������ �� �ִ� vertex���� ��� ã�� ���ؼ�....
	

	// DFS�� stack�� �̿�
	// 1. �����ϴ� vtx�� stack�� �־���� (A �ֱ�) 
	// 2. stack���� ���� (stack�� ��������) (A �湮) - A�� �湮�ߴٰ� ǥ�� 
	// 3. A�� �� �� �ִ� ���� �� �־� ���� (B, C) (�湮�� vtx, stack�� �� �ִ� �� ����) ---- ���� �ݺ�

	// BFS�� queue�� �̿�
	// 1. A�� queue�ֱ�
	// 2. A�� queue���� ������ (A �湮) - A �湮�ߴٰ� ǥ��
	// 3. A�� �� �� �ִ� �� �� �־� ���� (B,C) (�湮, queue�� ���� ����)

//  DFS�� ���� stack
int stack_DFS[NUM_VTX];
int top = -1;
void push(int v) {
	if (top == NUM_VTX - 1) {
		return;
	}
	top++;
	stack_DFS[top] = v;
	return;
}
int pop() {
	if (top == -1) {
		return -999;
	}
	int res = stack_DFS[top];
	top--;
	return res;
}

// BFS�� ���� queue
int queue_BFS[NUM_VTX];
int front = 0;
int rear = 0;

void enqueue(int v) {
	if (front == (rear + 1) % NUM_VTX) {
		return; // que is full
	}
	queue_BFS[rear] = v;
	rear = (rear + 1) % NUM_VTX;
	return;
}
int dequeue() {
	if (front == rear) {
		return -999; // que empty
	}
	int res = queue_BFS[front];
	front = (front + 1) % NUM_VTX;
	return res;
}

// stack�ȿ� v�� �̹� ������ 1
// �ƴϸ� 0�� ��ȯ
int checkDuplication(int v) {
	// stack�� ���������, v�� ����.
	if (top == -1) {
		return 0;
	}
	for (int i = 0; i <= top; i++) { // stack�� �� �������� v�� �ִ��� �˻�!
		if (stack_DFS[i] == v) {
			return 1;
		}
	}
	return 0;
}

// _v���� �����Ͽ�, DFS ����
void do_DFS(int _v) {
	// 1. stack_DFS : push, pop, checkDuplication
	// 2. visited : �湮�ߴ��� ���θ� ��Ÿ���� 1���� �迭
	int visited[NUM_VTX] = { 0, }; // ��δ� �湮���� �ʾ���.

	// �˰���
	// 
	// ���� vertex�� stack�� �ִ´�.
	// 
	// �ݺ� -- stack�� �������� 
	//	stack���� pop ---> m
	//	m�� �湮�ߴٰ� ǥ���ϰ�,
	//  m�� ȭ�鿡 ���
	//  for (m�� ����� ������ vertex�� ���ؼ�)
	//		if (stack�� ����, visited�� �ƴϸ�)
	//		   ==> push
	push(_v);

	while (1) {
		int m = pop();
		if (m == -999) {
			break;
		}
		if (visited[m] == 0) {
			visited[m] = 1;
			printf("%d vertex�� �湮����\n", m);
		}
		struct node* _cur = graph[m];
		while (_cur != 0) {
			//if (checkDuplication(_cur->vtx) == 0 && visited[_cur->vtx] == 0) {
			if (visited[_cur->vtx] == 0){
				push(_cur->vtx);
			}	
			_cur = _cur->next;
		}
	}


}

void do_BFS(int v) {
	int visited[NUM_VTX] = { 0, };

	enqueue(v);
	while (1) {
		int m = dequeue();
		if (m == -999) {
			break;
		}
		if (visited[m] == 0) {
			visited[m] = 1;
			printf("%d vertex�� �湮�Ͽ���\n", m);
		}
		else {
			printf("%d ------ �ߺ�\n",m);
		}
		struct node* _cur = graph[m];
		while (_cur != 0) {
			if (visited[_cur->vtx] == 0) {
				push(_cur->vtx);
			}
			_cur = _cur->next;
		}
	}
	
}

int main(void) {

	addEdge(0, 3); // 3 --> 0
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 4);
	addEdge(2, 4);
	addEdge(2, 4);
	addEdge(3, 5);
	addEdge(4, 5);

	//do_DFS(0); // 0�� vertex���� �����ؼ� DFS ����


	do_BFS(0); // 1�� vertex��Ÿ �����ؼ� BFS ����

	return 0;
}