// max heap ����

#include <stdio.h>

#define HEAP_SZ 100

int heap[HEAP_SZ + 1];
int idx = 0;

void addToMaxHeap(int _v) {
	// 1. heap full
	if (idx == HEAP_SZ) {
		printf("heap full\n");

	}
	idx++;
	heap[idx] = _v;

	// upheap ����
	int _cur = idx; // ���� �ε���
	while (_cur > 1) {
		int _p = _cur / 2; // �θ� �ε���
		if (heap[_p] >= heap[_cur]) {
			return;
		}
		else { //�θ� ���� ��ġ�� ����, ���� �θ� ��ġ��.
			heap[_p] = heap[_cur];
			int temp = heap[_p];
			heap[_cur] = temp;
			_cur = _p; // <---- �߿�, ���� �θ��� ��ġ�� upheap!!!


		}
	}
}
	
// ����, maxheap�� ��������� -999�� ��ȯ
int delFromMaxHeap(void) {
	// heap empty
	if (idx == 0) {
		return -999;
	}

	int res = heap[1]; //heap���� ������ ���� �׻� idx 1��

	//root�� �������ν�, �ر��� maxheap�� ����ϴ� ����


	// 1. �� ������ ���� root��ġ�� �ű��
	heap[1] = heap[idx];
	// 2. idx ����
	idx--;

	// downheap ����
	int _cur = 1; //���� ���� ��ġ
	while (1) {
		int child_idx = 2 * _cur; // ���� �����ڽ� �ε���
		if (child_idx > idx) {
			break;
		}
		//�ϴ� ������ �ڽ��� �ְ�,
		if ((child_idx <= idx - 1) && (heap[child_idx] < heap[child_idx + 1])) {
			child_idx = child_idx + 1; // �����ڽ��� ������ �� ���
		}

		if (heap[_cur] >= heap[child_idx]) {
			break; // ���� �ڽĺ��� Ŀ
		}
		else { // �ڽ��ڸ��� ���������Ѵ�.
			int temp = heap[_cur];
			heap[_cur] = heap[child_idx];
			heap[child_idx] = temp;
			_cur = child_idx;
		}
	}



	return res;
}





int main(void) {

	addToMaxHeap(20);
	addToMaxHeap(30);
	addToMaxHeap(5);
	addToMaxHeap(40);
	addToMaxHeap(15);
	
	//addToMaxHeap�� ����� �����Ǿ����� Ȯ���ϱ� ���ؼ�
	/*for (int i = 1; i <= idx; i++) {
		printf ("%d    %d\n", i, heap[i]);
	}*/
	while (1) {
		int res  = delFromMaxHeap();
		if (res == -999) {
			break;
		}
		printf("%d\n", res);
	}
	
	return 0;
}