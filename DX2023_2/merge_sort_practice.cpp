#include <stdio.h>
#include <stdlib.h>
void do_merge(int s, int m, int e, int nums[], int tarry[]) {
	int ls = s;
	int le = m;
	int rs = m + 1;
	int re = e;
	int i = ls;
	int j = rs;
	int t = ls;
	while (1) {
		if ((i > le) && (j > re)) {
			break;
		}

		if (i > le) {
			tarry[t] = nums[j];
			t++;
			j++;
		}
		else if (j > re) {
			tarry[t] = nums[i];
			t++;
			i++;
		}
		else {
			if (nums[i] > nums[j]) {
				tarry[t] = nums[j];
				t++;
				j++;
			}
			else {
				tarry[t] = nums[i];
				t++;
				i++;
			}
		}
	}

	for (int i = s; i <=e; i++) {
		nums[i] = tarry[i];
	}
	return;
}

void merge_sort(int s, int e, int nums[], int tarry[]) {
	if (s == e) {
		return;
	}
	merge_sort(s, (s + e) / 2, nums, tarry);
	merge_sort((s + e) / 2 + 1, e, nums, tarry);
	do_merge(s, (s + e) / 2, e, nums, tarry);
}






int main(void) {
	int nums[] = { 34,56,12,23,43,53 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	
	int* tarry = (int*)malloc(sizeof(int) * sz);
	merge_sort(0, sz - 1, nums, tarry);
	free(tarry);

	for (int i = 0; i < sz; i++) {
		printf("%d -> ", nums[i]);
	}
	printf("\n");
	return 0;
}