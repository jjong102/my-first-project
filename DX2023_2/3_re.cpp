#if 0

#include <stdio.h>
// �ŵ� �������� ��� recursion O(log_2 n)

int recur_power(int n, int m) {

	if (m == 0) {
		return 1;
	}
	else if (m == 1) {
		return n;
	}
	else if (m % 2 == 0) {
		return (recur_power(n, m / 2) * recur_power(n, m / 2));
	}
	else {
		return (n * recur_power(n, (m - 1) / 2)* recur_power(n, (m - 1) / 2));
	}
}


int main(void) {
	int n, m;
	printf("Put you number : ");
	scanf_s("%d %d", &n, &m);

	printf("%d�� %d������ %d�Դϴ�!\n", n, m, recur_power(n, m));





	return 0;
}
#endif