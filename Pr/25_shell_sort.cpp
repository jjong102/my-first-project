#include <stdio.h>

void shell_sort(int num_array[], int sz) {
	// 1. gap : sz/2--> �ݾ� ���̸鼭 --> 1�� �ɶ� ����..

	int gap = 0;
	int i = 0;
	int k = 0;


	for (gap = sz / 2; gap > 0; gap = gap / 2) {

		//insertion sort ������ �׷쿡 ���ؼ� �����Ѵ�.
		for (i = 0; i < gap; i++) {

			// �̰����� insertion sort�� �����Ѵ�. (gap��ŭ �������� ���ϴ� for��)
			for (k = i + gap; k < sz; k = k + gap) {
				int me = num_array[k]; // �ϴ�.������ ū �ְ� ���� �� �����Ƿ� �ڸ��� ��� �����ش�.
				int d = 0; //���� ���, �� �տ� �ִ� �ֵ�...
				for (d = k - gap; d >= 0 && num_array[d] > me; d = d - gap) {
					num_array[d + gap] = num_array[d];
				}
				num_array[d + gap] = me;
			}

		}
	}
}

int main(void) {
	int nums[] = { 23, 32, 34, 100, 87, 76, 23, 65, 2, 90, 21, 1, 3 };
	int sz = sizeof(nums) / sizeof(nums[0]);

	printf("sz is %d\n", sz);

	printf("-------------shell sort---------------\n");
	shell_sort(nums, sz);

	for (int i = 0; i < sz; i++) {
		printf("%d\n", nums[i]);
	}

	return 0;
}
