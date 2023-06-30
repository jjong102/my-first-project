
#include <stdio.h>
#include <stdlib.h>

void do_merge(int nums[], int tarry[], int start, int mid, int end) {

	int lstart = start;
	int lend = mid;
	int rstart = mid + 1;
	int rend = end;
	int i = lstart; // ���� ������ ���� ��ġ
	int j = rstart; // ������ ������ ���� ��ġ
	int t = lstart;

	while (1) {
		
		if ((i > lend) && (j > rend)) { // merge�� ���� ����
			break;
		}

		if (j > rend) { //���� ������ ���ڰ� ���� ���
			tarry[t] = nums[i];
			t++;
			i++;
		}

		else if (i > lend) { // ������ ������ ���ڰ� ���� ���
			tarry[t] = nums[j];
			t++;
			j++;
		}

		else { //���ʿ� ���ڰ� ���� �����Ƿ�, ���� ���ڸ� ã�Ƽ� �ִ´�.
			if (nums[i] < nums[j]) { //���� ���� ���ڰ� �۴�.
				tarry[t] = nums[i];
				t++;
				i++;
			}
			else { // ������ ���� ���ڰ� ũ��.
				tarry[t] = nums[j];
				t++;
				j++;
			}
		}

	}

	// tarry�� merge�� ����� �ִ�.
	// �̰��� ���� �迭�� �����ؼ� �־�� �Ѵ�.
	for (i = start; i <= end; i++) {
		nums[i] = tarry[i];
	}
}



void merge_sort(int nums[], int start, int end, int tarry[]) {
	// Ż������
	if (start == end) {
		return;
	}

	merge_sort(nums, start, (start + end) / 2, tarry); //������ merge sort
	merge_sort(nums, (start + end) / 2 + 1, end, tarry); //�������� merge sort
	// ���ʰ� �������� merge �Ѵ�.
	do_merge(nums, tarry, start, (start + end) / 2, end);
}

int main(void) {
	
	int nums[] = { 23 , 32, 34, 100, 87, 65, 2, 90, 21,1,3 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	// merge sort�� �����ϱ� ���� �ӽ� �����
	int* tarry = (int*)malloc(sizeof(int) * sz);

	//nums: ���Ĵ�� �迭
	// 0 : ���� index
	// 1 : ���� index
	// �ӽù迭 : extra space
	merge_sort(nums, 0, sz - 1, tarry);
	free(tarry);
	for (int i = 0; i < sz; i++) {
		printf("%d -->", nums[i]);
	}
	printf("\n");
	return 0;
}