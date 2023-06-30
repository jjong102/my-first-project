#include <stdio.h>
#define swap(a,b,temp) temp =a, a =b, b=temp

void showNums(int nums[], int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ---> ", nums[i]);
	}
	printf("\n");
}


void quick_sort(int s, int e, int nums[], int real_sz) {
	int l = s + 1;
	int h = e;
	int p = s;
	
	
	if (s >= e) {
		return;
	}

	while (l <= h) {
	

		while (nums[p] >= nums[l] && l <= e) {
			l++;
		}
		while (nums[p] <= nums[h] && h >= s + 1) {
			h--;
		}

		if (l < h) {
			int temp;
			swap(nums[l], nums[h], temp);
		}

	}
	
	int temp;
	swap(nums[p], nums[h], temp);

	showNums(nums, real_sz);
	quick_sort(s, h - 1, nums, real_sz);
	quick_sort(h + 1, e, nums, real_sz);
}



int main(void) {
	int nums[] = { 23, 32, 34, 100, 87, 76, 23, 65, 2, 90, 21, 1, 3 };

	int sz = sizeof(nums) / sizeof(nums[0]); // sizeof는 바이트 단위로 변수의 크기를 반환함. 이렇게 설정하면  sz에 개수가 들어감.

	showNums(nums, sz);
	quick_sort(0, sz - 1, nums, sz);
	showNums(nums, sz);

	return 0;

}