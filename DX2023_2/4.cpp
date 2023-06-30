// P.53 피보나치수열의 계산
// 0,1,1,2,3,5,8,13 .....
// 전역 변수, 배열을 이용한 계산
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
	
	printf("몇번째 피보나치 수열을 출력할까요? ");
	
	scanf_s("%d", &n);
	for (int i = 3; i <= n ; i++) {
		fi[i] = -1;
	}
	printf("%d번째 피보나치 수열은 %d입니다!\n", n, fibo(n));

	return 0;
}
#endif