// �ŵ� �������� ���
// 2 ^ 3 = 2*2*2
//recursion �̿�
#if 1
#include <stdio.h>

//recursion power, �� �� ������ 2^10 ---> 4^5(���� ������)[�������� ���� ����Ʈ���� ���� ����Ʈ]
									// ---> ������ 5�� 2�� ���� ��������
									// ---> 4 * 4^4
									// ---> 4 * 16^2
									// ---> 4 * (16^2)^1	10 ---> 4�ܰ��
// O(log_2 n)
int my_power_fast(int a, int b) {
	
	if (b == 1) {
		return a;
	}
	
	//b�� ¦��
	if (b % 2 == 0) {
		return my_power_fast(a * a, b / 2);
	}

	//b�� Ȧ��
	else {
		return a * my_power_fast(a * a, (b - 1) / 2);
	}

}




//O(n)  ---> O(log_2 n)
int my_power_recursion(int a, int b) { //a^b�� �輱�ؼ� ��ȯ
	// recursion�� �̿��� �ع�
	
	//Ż������
	if (b == 1) {
		return a;
	}
	
	return a * my_power_recursion(a, b - 1);

}




//O(n)
int my_power(int a, int b) { //a^b�� �輱�ؼ� ��ȯ
	// �ݺ��� �̿��� �ع�
	int res = 1;
	int i;

	for (i = 1; i <= b; i++) {

		res = res * a;
	}
	return res;

}



int main(void) {
	int res = my_power(2, 3);


	return 0;
}
#endif