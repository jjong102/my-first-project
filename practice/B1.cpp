#include <stdio.h>

#define Q_SZ 4
int que[Q_SZ];

int front = 0;
int rear = 0;


void enqueue(int _v) {
	if ((rear + 1) % Q_SZ == front) {
		front = (front + 1) % Q_SZ;
		rear = (rear + 1) % Q_SZ;
		que[rear] = _v;
		return;
	}

	
	rear = (rear + 1) % Q_SZ;
	que[rear] = _v;
	return;
}

int dequeue(void) {
	if (rear == front) {
		return -999;
	}

	int res = que[front];
	front = (front + 1) % Q_SZ;
	return res;
}



int main(void) {
	int v;
	while (1) {
 		scanf_s("%d", &v);
		if (v == 0) {
			break;
		}

		else if (v == -1) {
			dequeue();
		}
		else {
			enqueue(v);
		}
	}

	printf("%d", dequeue());


	return 0;
		
}

	
