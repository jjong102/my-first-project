// �ϳ��� Ÿ�� p.56

// n : ��� ���ø� �ű����, n���� ���ø� �Űܶ�!
// form ���뿡��
// team ���븦 �ӽ÷� Ȱ���ؼ�
// to ����� �ű�ÿ�
#if 0
#include <stdio.h>

void hanoi_tower(int n, int form, int temp, int to) {
	//Ż��
	
	if (n == 1) {
		printf("%d ���� %d�� ���� �Ѱ� �����Դϴ�.\n", form, to);
		return;
	}

	hanoi_tower(n-1, form, to, temp);
	// ���������� �� �ϳ���, form���� to�� �ű��.
	printf("%d ���� %d�� ���� �Ѱ� �����Դϴ�.\n", form, to);
	hanoi_tower(n-1, temp, form, to);


}

int main(void) {
	
	hanoi_tower(4, 1, 2, 3);

	return 0;
}
#endif