// deque ����

#if 0
#include <stdio.h>
#define qu_sz 20

int que[qu_sz];
int front = 0; // ���� + �ֱ�
int rear = 0;  // �ֱ� + ����

int isFull() {
	return (((rear + 1)%qu_sz) == front); //�ڷ� ���ư��� ��� ����
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

	front = ((front - 1 + qu_sz) % qu_sz); // front�� ������ ���� �� �ֱ� ����
	que[front] = _v;
	return;
}

int del_from_rear(void) {
	if (isEmpty()) {
		printf("queue is empty\n");
		return -999;
	}

	rear = ((rear - 1 + qu_sz) % qu_sz);
	return que[rear]; // �ּҸ� ��ȯ
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