//----------------------------------------
// �ݺ��� �̿��� recursion
//----------------------------------------
#if 0
#include <stdio.h>

// �ݺ����� Ǫ�°� ����, �� ������ (recursion �׻� �Լ� ������ ���� ����, ��ȿ�����̴�)
int factorial(int n) { 

	int result = 1;
	int i;
	for (i = 1; i <= n; i++) {
		result = result * i;
	}

	return result;
}
	



int main(void) {
	int n = 5;
	int k = factorial(n);

	printf("%d�� factorial�� %d�Դϴ�.\n", n, k);

	return 0;
}
#endif