#include <stdio.h>
#define	Q_SZ 10

// queue
int que[Q_SZ]; 
int front = 0;
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() { 	
	return (((rear + 1) % Q_SZ) == front);  
}


void enqueue(int _v) {
	if (isFull()) {
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

int del_from_rear() {
	
	if (isEmpty()) {
		return -999;
	}
	rear = (rear - 1 + Q_SZ) % Q_SZ;
	return que[rear];

}

    

int main(void) {
	int n;
	scanf_s("%d ", &n);
	while (n != 0) {
		if (n == -1) {
			dequeue();
		}
		else {
			enqueue(n);
		}
		scanf_s("%d", &n);
	}

	int i, j, tmp = 0;
	for (i = 0; i <= rear-1 ; i++) {
		for (j = i; j <= rear-1; j++) {
			if (que[i] > que[j]) {
				tmp = que[i];
				que[i] = que[j];
				que[j] = tmp;
			}
		}
	}

	if (isEmpty()) {
		printf("0");
		return 0;
	}
	else {
		while (!isEmpty()) {
			printf("%d ", del_from_rear());
		}
	}

	return 0;
}