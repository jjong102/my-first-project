// deque 구현

#if 0
#include <stdio.h>
#define qu_sz 20

int que[qu_sz];
int front = 0; // 빼기 + 넣기
int rear = 0;  // 넣기 + 빼기

int isFull() {
	return (((rear + 1)%qu_sz) == front); //뒤로 돌아가는 경우 생각
}

int isEmpty() {
	return (front == rear);
}

void enqueue(int _v) {
	if (isFull()) {
		printf("queue is full\n");
		return;
	}

	que[rear] = _v;
	rear = ((rear + 1) % qu_sz);
	return;
}

int dequeue(void) {
	if (isEmpty()) {
		printf("queue is empty\n");
		return -999;
	}

	int result = que[front];
	front = ((front + 1) % qu_sz);
	return result;
}

void add_to_front(int _v) {
	if (isFull()) {
		printf("queue is full\n");
		return;
	}

	front = ((front - 1 + qu_sz) % qu_sz); // front가 음수가 나올 수 있기 떄문
	que[front] = _v;
	return;
}

int del_from_rear(void) {
	if (isEmpty()) {
		printf("queue is empty\n");
		return -999;
	}

	rear = ((rear - 1 + qu_sz) % qu_sz);
	return que[rear]; // 주소를 반환
}

int main(void) {
	add_to_front(10);
	enqueue(20);
	enqueue(30);
	add_to_front(40);

	while (!isEmpty()) {
		printf("%d\n", del_from_rear());
	}
	return 0;





	return 0;
}
endif