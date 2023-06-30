#include <stdio.h>
#include <stdlib.h>

#define NUM_VTX 4

typedef struct node {
	int vtx;
	node* next;
}node;

node* graph[NUM_VTX];


void _addEdge(int v1, int v2) {
	node* _v2 = (node*)malloc(sizeof(node));
	_v2->vtx = v2;
	_v2->next = 0;
	node* cur = graph[v1];

	if (cur == 0) {
		graph[v1] = _v2; 
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

void addEdge(int v1, int v2) {

	_addEdge(v1, v2);
	_addEdge(v2, v1);
}

int isThereEdge(int v1, int v2) {
	node* cur = graph[v1];

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

int isTherePath(int v1, int v2) {

	return 0;
}




int main(void) {

	addEdge(0, 3); // 3 --> 0
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);

	printf("%d\n", isThereEdge(1, 3)); // edge는 단번에 가는 것!
	printf("%d\n", isThereEdge(0, 3));

	// printf("%d\n", isTherePath(1, 3)); // path는 어떻게든 연결되어 있는 것!

	
	

	return 0;
}