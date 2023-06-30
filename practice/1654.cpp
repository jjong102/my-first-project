#include <stdio.h>

#define SZ 11

int heap_m[SZ];
int heap_M[SZ];
int idx = 0;

void addToMinHeap(int _v) {
	if (idx == SZ) {
		return;
	}
	
	idx++;
	heap_m[idx] = _v;
	int _cur = idx;
	while (_cur > 1) {
		int _p = _cur / 2;
		if (heap_m[_p] <= heap_m[_cur]) {
			return;
		}
		else {
			int temp = heap_m[_p];
			heap_m[_p] = heap_m[_cur];
			heap_m[_cur] = temp;
			_cur = _p;
		}
	}
}

void addToMaxHeap(int _v) {
	if (idx == SZ) {
		return;
	}
	
	idx++;
	heap_M[idx] = _v;
	int _cur = idx;
	while (_cur > 1) {
		int _p = _cur / 2;
		if (heap_M[_p] >= heap_M[_cur]) {
			return;
		}
		else {
			int temp = heap_M[_p];
			heap_M[_p] = heap_M[_cur];
			heap_M[_cur] = temp;
			_cur = _p;
		}
	}
}

int delFromMinHeap(void) {
	if (idx == 0) {
		return -999;
	}


	int res = heap_m[1];
	heap_m[1] = heap_m[idx];
	idx--;
	int _cur = 1;
	while (1) {
		int child_idx = _cur * 2;
		if (child_idx > idx) {
			break;
		}

		if (child_idx >= idx-1 && (heap_m[child_idx] > heap_m[child_idx + 1])) {
			child_idx = child_idx + 1;
		}

		if (heap_m[_cur] < heap_m[child_idx]) {
			break;
		}

		else {
			int temp = heap_m[_cur];
			heap_m[_cur] = heap_m[child_idx];
			heap_m[child_idx] = temp;
			_cur = child_idx;
		}
	}
	return res;

}

int delFromMaxHeap(void) {
	if (idx == 0) {
		return -999;
	}

	int res = heap_M[1];
	heap_M[1] = heap_M[idx];
	idx--;
	int _cur = 1;
	while (1) {
		int child_idx = _cur * 2;
		if (child_idx > idx) {
			break;
		}

		if (child_idx >= idx-1 && (heap_M[child_idx] < heap_M[child_idx + 1])) {
			child_idx = child_idx + 1;
		}

		if (heap_M[_cur] < heap_M[child_idx]) {
			break;
		}

		else {
			int temp = heap_M[_cur];
			heap_M[_cur] = heap_M[child_idx];
			heap_M[child_idx] = temp;
			_cur = child_idx;
		}
	}
	return res;

}

int main(void) {
	while (1) {
		int v;
		scanf("%d", &v);
		if (v == -1) {
			printf ("%d",delFromMinHeap());
			return 0;
		}
		if (v == -2) {
			printf("%d",delFromMaxHeap());
			return 0;
		}
		addToMinHeap(v);
		addToMaxHeap(v);
	}
	return 0;
}