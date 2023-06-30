// recursion을 이용한 factorial 구현
#if 0
#include <stdio.h>

int recurfac(int n) {
	if (n == 1) {
		return 1;
	}
	else return (n * recurfac(n - 1));
}



int main(void) {
	int n;
	scanf_s("%d", &n);
	printf ("%d\n", recurfac(n));

	return 0;
}
#endif