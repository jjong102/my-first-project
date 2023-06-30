#include <stdio.h>
#define Q_SZ 20

int que[Q_SZ];
int rear = 0;
int front = 0;

int isFull(void) {

	return ((rear + 1) % Q_SZ) == front;
}

int isEmpty(void) {
	return (rear = front);

}

void enqueue(int _v) {
	if (isFull()) {
		return;
	}
	rear = (rear + 1) & Q_SZ;
	que[rear] = _v;
	return;
}

int main(void) {


	return 0;
}