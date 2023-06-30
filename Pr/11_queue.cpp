//--------------------------------------------
// p. 146 Queue (ť)
// 
// ���ڼ��� : FIFO (frist in, frist out), ��ο� ���� ���� front(�ⱸ), vear(�Ա�)
// 
// stack : push, pop
// queue : enqueue (enter queue)
//		 : dequeue (depart from queue)
//			departure <---> arrival
// 
// ����
// queue�� �������� �迭�� ����Ѵ�.
// front, rear <----- ť���� ��ġ�� ��Ÿ���� ����
// front : dequeue�� ���� �ִ� ��ġ (���� ���� ��)
// rear  : enqueue�� ��ġ (���� �ִ� ��)
// 
// front�� rear�� ���� ���� ����Ű�� ������ queue�� ��� �ִ�! (������ ���� ���� ����Ŵ) ---> �׳� ��ĭ�� �����
// �ϳ��� ���� front�� ������ �̵��Ѵ�. 
//		- ��� �ִ� ������ ã�� �̵�!
// �ϳ��� �����ϸ� rear�� �̵��Ѵ�. (2 ����)
//		1. �տ� �ִ� ���� �� ����� �� �ڿ� ���� (����µ� �ð��� ���� �ɷ�!!, ��ȿ����) 
//		2. rear�� ����ִ� ������ ã�� �̵� (ȿ����) [circular queue]
//
//		1. ������ ���� ���... �̰��� ��ȿ����
//		2. �Ϲ����� ť ���������, dequeue�ǰ� ����, �����͸� ��ĭ��
//		
// 
// queue�� isEmpty�� isFull�� ����
// 
// circular queue�� 1ĭ�� ������ν�, empty�� full�� ����
//		�ִ� ���� �뷮�� N - 1 
//--------------------------------------------

#if 1
#include <stdio.h>
#define	Q_SZ 10 //�ִ� 9��,circular queue�� ���
int que[Q_SZ]; // �߿��� ��ġ ����,

int front = 0;
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() { //rear �տ�(�ڿ�) front�� ������, full
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