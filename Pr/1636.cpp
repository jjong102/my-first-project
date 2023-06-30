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
		else if (n != 0) {
			enqueue(n);
			int i, j = 0;
				for (i = 0; i <= rear - 1; i++) {
					if (i != rear-1 && n == que[i] ){
						for (j = rear-1; j >= i+1; j--) {
							que[j + 1] = que[j];
						}
						que[i + 1] = n;
						rear++;
						break;
					}
				}	
			
		}
		scanf_s("%d", &n);
	}


	if (isEmpty()) {
		printf("0");
		return 0;
	}
	else {
		while (!isEmpty()) {
			printf("%d ", dequeue());
		}
	}

	return 0;
}