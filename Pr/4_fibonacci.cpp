// P.53 �Ǻ���ġ������ ���
// 0,1,1,2,3,5,8,13 .....
// �ռ� �ΰ� ���� ���� ���� ��
// recursion�� �̿�


//n��° �Ǻ���ġ ���� ��ȯ�ϴ� �Լ�
//0��° : 0
//1��° : 1
//2��° : 1
#if 1
#include <stdio.h>

int a[] = {0, 1, }; // �������� ������ �迭 ����
//
//
// 3. ���̺� �̿�, �迭�� �̿��� �ð� ������ ������.(��������) o(n)
int fibo_r(int n) {

	if (a[n - 1] == -1) {
		if (a[n - 2] != -1 && a[n - 3] != -1) {
			a[n - 1] = a[n - 3] + a[n - 2];
		}
		else {

		}
		return fibo_r(n - 2) + fibo_r(n - 1);
	}
	else {
		return a[n - 1];
	}
}



// 1. recursion�� �̿��� fibonacci ��� O(2^n)
//int fibo_r(int n) {
//	
//	//Ż������
//	if (n == 0) {
//		return 0;
//	}
//	if (n == 1) {
//		return 1;
//	}
//
//	return fibo_r(n - 2) + fibo_r(n - 1);
//}



 // 2. �ݺ��� �̿��� ���
int fibo(int n) {
	
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	int pp = 0;     // previous-previous
	int p = 1;      // previous
	int result = 0; // �����


	for (int i = 2; i <= n; i++) {
		result = pp + p;
		pp = p;
		p = result;
	}

	return result;
}

int main(void) {
	int n = 0;
	int i;

	scanf_s("%d", &n);
	/*for (i = 2; i <= n - 1; i++) {
		a[i] = -1;
	}*/

	printf ("%d\n", fibo_r(n));

	return 0;
}
#endif