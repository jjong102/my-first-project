// �ݺ��� �̿���  factorial
#if 0
#include <stdio.h>


int fac(int n) {
	int num = 1;
	
	for (int i = 1; i <= n; i++) {
		num = num * i;
	}

	return num;
}







int main(void) {
	int n;

	printf("���ڸ� �Է��� �ּ���! : \n");

	scanf_s("%d", &n);

	printf("%d�� factorial�� %d�Դϴ�!\n", n , fac(n));

	return 0;
}
#endif