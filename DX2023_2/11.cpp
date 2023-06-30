// queue 구현

// 4가지 함수 구현
#if 0
#include<stdio.h>
#define queue_sz 10

int queue[queue_sz];
int front = 0;  //빼기
int rear = 0; //넣기

int isEmpty(void) {
	return (front == rear);
}

int isFull(void) {
	return (((rear + 1) % queue_sz) == front);// rear의 한칸 다음이 front면 full
}

void enqueue(int _v) {
	if (isFull()) {
		printf("queue is full\n");
		return;
	}

	queue[rear] = _v;
	rear = (rear + 1) % queue_sz;
}

int dequeue(void) {
	if (isEmpty()) {
		printf("queue is empty\n");
		return -999;
	}

	int result = queue[front];
	front = (front + 1) % queue_sz;
	return result;
}

int main(void) {
	enqueue(4);
	enqueue(5);
	enqueue(7);

	while (!isEmpty()) {
		printf("%d\n", dequeue());
	}

	return 0;
}

#endif
