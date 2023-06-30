

#include <stdio.h>
#define	Q_SZ 10 


int que[Q_SZ]; 
int front = 0;
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() { 	return (((rear + 1) % Q_SZ) == front);  }


void enqueue(int _v) {
	if (isFull()) {
		printf("error, full\n");
		return;
	}

		que[rear] = _v;
		rear = (rear + 1) % Q_SZ;
	return;

}

int dequeue() {
		if (isEmpty()) {
		return -999; 	
		}

		int result = que[front];

		front = (front + 1) % Q_SZ;

		return result;

}


int main(void) {
	int n;
	scanf("%d ", &n);
	while (1) {
		if (n == 0) {
			break;
		}
		if (n == -1) {
			dequeue();
			
		}
		else {
			enqueue(n);
		}
		scanf("%d", &n);
	}

	if (isEmpty()) {
		printf("-999");
	}
	else {
		printf("%d", que[front] + que[rear-1]);
	}

	return 0;
}
