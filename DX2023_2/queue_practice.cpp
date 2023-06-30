#include <stdio.h>
#define SZ 10

int front = 0;
int rear = 0;

int que[SZ];

int isFull(void) {
	return ((rear + 1)%SZ == front);
}

int isEmpty(void) {
	return (front == rear);
}

void enqueue(int v) {
	if (isFull()) {
		return;
	}

	rear = (rear + 1) % SZ;
	que[rear] = v;
	return;
}

int dequeue(void) {
	if (isEmpty()) {
		return -999;
	}
	int temp = que[front];
	front = (front + 1) % SZ;
	return temp;
}



int main(void) {

	return 0;
}