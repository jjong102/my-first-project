// P.53 �Ǻ���ġ������ ���
// 0,1,1,2,3,5,8,13 .....
// ���� ����, �迭�� �̿��� ���
#if 0
#include <stdio.h>

int fi[] = { 0,1,1, };


int fibo(int n) {
	
	if ( fi[n - 1] == -1 ){
		fi[n - 1] = fibo(n - 1) + fibo(n - 2);
	}
	else if (n > 3 && fi[n - 1] != -1){
		return (fibo(n - 1) + fibo(n - 2));
	}
	
}



int main(void) {
	int n;
	
	printf("���° �Ǻ���ġ ������ ����ұ��? ");
	
	scanf_s("%d", &n);
	for (int i = 3; i <= n ; i++) {
		fi[i] = -1;
	}
	printf("%d��° �Ǻ���ġ ������ %d�Դϴ�!\n", n, fibo(n));

	return 0;
}
#endif