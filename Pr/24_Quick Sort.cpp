#include <stdio.h>

void showNums(int nums[], int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ---> ", nums[i]);
	}
	printf("\n");
}
// nums �迭��
// idxa ��ġ�� ����
// idxb ��ġ�� ���� �ٲ���ִ� �Լ�

void doSwap(int nums[], int idxa, int idxb) {
	int temp = nums[idxa];
	nums[idxa] = nums[idxb];
	nums[idxb] = temp;
}


void quick_sort(int nums[], int start, int end, int real_sz) {

	int pivot = start;
	int low = start + 1;
	int high = end;
	if (start >= end) { //Ż�� ����
		return;
	}

	while (low <= high) {

		while (nums[low] <= nums[pivot] && low <= end) {
			low++;
		}

		while (nums[high] >= nums[pivot] && high >= start + 1) {
			high--;
		}

		if (low < high) {
			doSwap(nums, low, high);
		}
	}

	// pivot�� �ڱ� �ڸ��� ã�ư����� �Ѵ�.
	doSwap(nums, pivot, high);

	showNums(nums, real_sz);  //sizeof�� ����Ͽ� ������ ���� �� ����.

	quick_sort(nums, start, high - 1, real_sz);
	quick_sort(nums, high + 1, end, real_sz);
}


int main(void) {
	int nums[] = { 23, 32, 34, 100, 87, 76, 23, 65, 2, 90, 21, 1, 3 };

	int sz = sizeof(nums) / sizeof(nums[0]); // sizeof�� ����Ʈ ������ ������ ũ�⸦ ��ȯ��. �̷��� �����ϸ�  sz�� ������ ��.

	showNums(nums, sz);
	quick_sort(nums, 0, sz - 1, sz);
	showNums(nums, sz);

	return 0;

}
