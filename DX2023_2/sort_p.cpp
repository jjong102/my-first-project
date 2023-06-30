#include <stdio.h>
#define SZ 5
#define swap(a,b,temp) temp=a, a=b, b=temp
int main_bubble(void) {
	int num[] = { 1, 10, 4, 5, 2 };
	for (int j = 0; j < SZ - 1; j++) {
		for (int i = 0; i < SZ - 1 - j; i++) {
			if (num[i] > num[i + 1]) {
				int temp;
				swap(num[i], num[i+1], temp);
			}
		}
	}

	for (int i = 0; i < SZ; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}

int main_selection(void) {
	int num[] = { 1, 10, 4, 5, 2 };

	for (int j = 0; j < SZ; j++) {
		int sidx = j;
		for (int i = j; i < SZ; i++) {
			if (num[i] < num[sidx]) {
				sidx = i;
			}
		}
		int temp;
		swap(num[j], num[sidx], temp);
	}

	for (int i = 0; i < SZ; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}

int main_InsertionSort(void) {
	int num[] = { 1, 10, 4, 5, 2 };
	for (int j = 0; j < SZ-1; j++) {
		for (int i = j + 1; i >=0; i--) {
			if (num[i] < num[i - 1]) {
				int temp;
				swap(num[i], num[i - 1], temp);
			}
		}
	}
	for (int i = 0; i < SZ; i++) {
		printf("%d\n", num[i]);
	}
	return 0;
}