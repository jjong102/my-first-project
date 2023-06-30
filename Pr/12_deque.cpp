//---------------------------------------------------------
// p. 162 ��
// deque
// 
// double ended queue (���� ���⿡�� ������ ������ ���� ����)
// 
//---------------------------------------------------------
#if 1
#include <stdio.h>
#define	Q_SZ 10 //�ִ� 9��,circular queue�� ���
int que[Q_SZ]; // �߿��� ��ġ ����,

int front = 0;
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() { //rear �ڿ� front�� ������, full
	return (((rear + 1) % Q_SZ) == front);  // �ڷ� ���ư��� ��찡 �ֱ� ������ ������ Ȱ��
}


void enqueue(int _v) {
	if (isFull()) {
		printf("error, full\n");
		return;
	}

	//rear�� ����Ű�� �ִ� ���� ��ġ�� �ִ´�.
	que[rear] = _v;
	// rear�� 1�� ���� ��Ų��. ,, �׻� �ڷ� ���ư��� ��츦 ����
	rear = (rear + 1) % Q_SZ;
	return;

}

int dequeue() {
	// empty üũ
	if (isEmpty()) {
		return -999; // errorǥ�� -999
	}

	// front ��ġ�� �ִ� �� �̱�
	int result = que[front];

	// front ����
	front = (front + 1) % Q_SZ;

	// �̾� ���� �� ��ȯ
	return result;

}

//deque�� �Ǳ� ����, 2���� �Լ�
// 1. add_to_front
// �켱, full���� üũ�ϰ�, �ƴϸ�,
// ���� front�� -1 ������,, �ѹ���??
//		front ��ġ�� _v�� �ִ´�.
void add_to_front(int _v) {
	if (isFull()) {
		printf("queue full\n");
		return;
	}
	front = (front - 1 + Q_SZ) % Q_SZ; // <-------- �ѹ��� ������ ���� ��
	que[front] = _v;
	return;
}



// 2. del_from_rear
int del_from_rear() {
	// empty ���� üũ
	if (isEmpty()) {
		return -999;
	}
	// rear�� ����
	rear = (rear - 1 + Q_SZ) % Q_SZ;

	//rear ��ġ�� ���� ��ȯ
	return que[rear];

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
}
#endif