//----------------------------------------
// recursion�� �̿��� factorial ����
// recursion�� ����Ҷ� �����ؾ���, ����� ���� ���� 
// �޸� �Ҵ��� ���� ��, �ʱⰪ�� �ٿ �Ǳ� �������� �޸� ����
//----------------------------------------
#if 1
#include <stdio.h>


int factorial(int n) {
	//Ż�������� �׻� ����������
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}




int main(void) {
	int n = 5;
	int k = factorial(n);

	printf("%d�� factorial�� %d�Դϴ�.\n", n, k);

	return 0;
}
#endif