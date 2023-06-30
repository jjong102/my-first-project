// 반복을 이용한  factorial
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

	printf("숫자를 입력해 주세요! : \n");

	scanf_s("%d", &n);

	printf("%d의 factorial은 %d입니다!\n", n , fac(n));

	return 0;
}
#endif