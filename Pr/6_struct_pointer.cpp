// �迭, ����ü, ������ p.70
// �迭 : ���� ������ Ÿ��, ����������, 0~n-1��
// ũ�� ���� �Ұ�


// ����ü struct p.73
// ���ο� ������ Ÿ���� ����� ���
// ������ Ÿ���� �ٸ� �͵��� ��Ƽ� ���� �� �ִ�.

// P.76 ~ 88 �� ��������

#if 1
#include <stdio.h>


// �迭
int main(void) {
	int a[10]; // ������ �迭 
	int aa[3][3]; // ---> aa[0][0], a[0][1] ..... a[2][2] ������ �迭
				  // ������ ����Ǵ� ���� ������

	return 0;
}


//����ü
// ����� �� �����͸� �����ϰ� �ʹ�.
// ������� ���� ��ȣ(����)�� �ְ�, ���� ������ �����ϰ� �ʹ�.


// int
// char === struct Person 
// float

// struct -----> class[��ü](�� �� �ִ� ���� �Լ��� ���� �� ����.)



typedef struct { // typedef ���̿� �̸��� ����. ª�� ���� ������..
	int id;
	int age;
	float height; 
} PersonA; // �̸�


struct Person {
	int id;
	int age;
	float height; //Ű����
};

int main(void) {

	// struct Person
	PersonA a = { 2, 19, 160.0 }; // ���� a�� �ϳ� �����, �̰��� ������ ���� struct Person

	a.id = 1;
	a.age = 20;
	a.height = 170.0;

	return 0;
}
#endif