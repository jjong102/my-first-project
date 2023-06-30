#include <stdio.h>

#define SZ 100

int heap[SZ];
int idx = 0;

void addToMaxHeap(int _v) {
	if (idx == SZ) {
		return;
	}
	idx++;
	heap[idx] = _v;

	int _cur = idx;
	while (1) {
		int _p = idx / 2;
		if (heap[_p] > heap[_cur]) {
			return;
		}
		else {
			int temp = heap[_cur];
			heap[_cur] = heap[_p];
			heap[_p] = temp;
			_cur = _p;
		}
	}
}

int delFromMaxHeap(void) {
	if (idx == 0) {
		return 999;
	}
	heap[idx]


}


int main(void) {
	addToMaxHeap(20);
	addToMaxHeap(30);
	addToMaxHeap(5);
	addToMaxHeap(40);
	addToMaxHeap(15);

	//addToMaxHeap이 제대로 구현되었는지 확인하기 위해서
	/*for (int i = 1; i <= idx; i++) {
		printf ("%d    %d\n", i, heap[i]);
	}*/
	while (1) {
		int res = delFromMaxHeap();
		if (res == -999) {
			break;
		}
		printf("%d\n", res);
	}

	return 0;
	
}