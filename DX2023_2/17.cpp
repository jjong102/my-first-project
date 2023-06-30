#include <stdio.h>

#define SZ 100

int heap[SZ + 1];
int idx = 0;

void addToMaxHeap(int _v) {
	if (idx == SZ) {
		printf("heap is full\n");
	}
	idx++;
	heap[idx] = _v;

	int _cur = idx;
	while (_cur > 1) {
		int _p = _cur / 2;
		if (heap[_p] > heap[_cur]) {
			return;
		}
		else {
			int temp = heap[_p];
			heap[_p] = heap[_cur];
			heap[_cur] = temp;
			_cur = _p;
		}
	}
}

int delFromMaxHeap(void) {
	if (idx == 0) {
		return -999;
	}
	
	int res = heap[1];
	heap[1] = heap[idx];
	idx--;

	int _cur = 1;
	while (1) {
		int child = _cur * 2;
		if (child > idx) {
			break;
		}
		
		if ((child >= idx - 1) && (heap[child] < heap[child + 1])) {
			child = child + 1;
		}
		
		if (heap[_cur] > heap[child]) {
			break;
		}
	

		else {
			int temp = heap[child];
			heap[child] = heap[_cur];
			heap[_cur] = temp;
			_cur = child;
		}
	}
	

}



int main(void) {

	return 0;
}