// ������ Pointer p.89
// ������ Ÿ�� ���� �ϳ�, 
// int, char : ���� ��� ������ Ÿ��
// Pointer type : �ּҸ� ��� ������ Ÿ�� (�ϵ����� ģ��)

#include <stdio.h>
#include <stdlib.h> // standard libracy < === malloc, free
#if 1
int main(void) {

	int a = 10; //��� ���� �ּ����� ����� ���ϰ� ���� ���� ���� ����

	// ������ ����� ��ġ (�ּ�)�� �����ϱ� ���� ����
	// ���� ==> pointer

	// �ּҸ� �����ϱ� ���� ��������, pointer type
/*
	int* // * : �ּҸ� �����ϴ� Ÿ�� �ǹ�, 
		 // int : �����͸� �̿��ؼ� �� ��ġ���� 1���� �ϰ� �� �� �ִ� �����ͷ�, int == 4byte
		
	short* // 2byte
	char*  // 1byte
*/
	// pa�� pc�� �����ϴ� �޸� ������ ũ��� �ٸ���? 
	// == �Ȱ���! �׻� 4byte pointer (������ ó���� �� �ִ� byte���� �ٸ���!)
	int* pa;
	char* pc;
	float* pf;

	// p.90 null pointer
	// �ƹ��͵� ����Ű�� �ʴ� ������.
	// NULL, 0 ==> ������ ���� �ȿ� ����� �ּҰ� �ùٸ� ������, �ƴ��� ������ �ִ� ����

	int* pa = 0;
	int* pb = NULL;

	// p. 90 ������ ������
	// 1. �ּ� ������
	int a = 10;
	// &a // ���� a�� ����Ǿ� �ִ� �޸� ���� �ּ�.

	// int* pa = 0;
	// &pa // �ּ��� �ּ�// ������ ������ �޸𸮸� �Ҵ� �޴´�.

	// 2. �������� ������, *
	// ����!!! pointer������ ���ؼ��� ���밡��!!!
	int a = 20;
	int* pa = &a;
	scanf("%d", &a); //==> �ּ� �������� ���

	printf("%d  %d\n", a, *pa); // ������ ���� �ּҸ� ���������� ã�Ƽ� ������ ã�ƿ��� ����
								// 20, 20 �Ȱ��� ��µ�!! // *pa�� �� �ּҰ� ������ �ִ� ���� ��Ÿ���� ��.
	printf("%d  %d   %d\n", &a, pa, &pa); // a�� �ּ�, a�� �ּ�(pa�� ��� �ִ� ��), ������ ����pa��ü�� �ּ�



	return 0;
}
#endif


// p.91 �Լ� �Ű������� ������ ����ϱ�
#if 0
// call by reference <--- �����͸� �̿��Ͽ� ����
void real_change(int* x, int* y) { // ���� ���� �ּҸ� ������
	int temp;
	
	temp = *x; // read
	*x = *y; // write
	*y = temp;

}


// call by value , ���纻�� �Ѿ.
void change_two_num(int a, int b) { 
	int temp;
	temp = b;
	b = a;
	a = temp;
	return;
}


int main(void) {

	int a = 10;
	int b = 20;

	printf("%d %d\n", a, b); // 10, 20
	change_two_num(a, b);
	printf("%d %d\n", a, b); // 10, 20 , ���纻�� �ٲ� ��Ȳ <---- call by value
	real_change(&a, &b);
	printf("%d %d\n", a, b); // 20, 10 <--- call by reference



	return 0;
}
#endif




// p. 92 �迭�� ������
// ģ���� ����
// �迭 : ���� ���������� ������ �޸��� "���ӵ� ����"�� ����Ǿ� �ִ� ��.
// int a[10]; 10���� ������ �޷��........
#if 0
int main(void) {

	int a[10];

	printf("%d %d\n", a[10], a[9]);
	
	// �迭�� ������
	// �迭 �̸��� ������ �� ��ü
	printf("%d\n", a); // �迭�� ����� ���� ���� ��ġ, �ּ�, �迭�̸��� ������ �� ��ü

	// a === &a[0]

	// a+1 == &a[1] // �ε��� 1�� ��ġ�� a+1�� ���� ���� �ǹ�



	return 0;
}
#endif


// P.94, ���� �޸� �Ҵ� <====> ���� �޸� �Ҵ�
// �����޸� : �������� �� ����ϴ� �޸𸮾��� ��� ����,
// �����޸� : �����ϸ鼭 �޸� �Ҵ�, �ӵ��� ����....., �ü���� �뻧, �׷��� ���ϴ� ��ŭ ��,
//			   ��, free�� ���ϸ� �޸� ����
//			   ���α׷��� ��� ����Ǹ�, malloc�� ����ϰ�, free�� �� �ϸ�, memory leak
// malloc (memory allocation)
// free (�޸� ����)
#if 1
int main(void) {

	// unreferenced space problem.
	char* p = (char *)malloc(100); // 100 ����Ʈ ������ �Ҵ��ؼ�, �����ּҸ� ��ȯ�Ѵ�.
						// casting�� ���ؼ� �ּ� Ÿ���� ���������.
	if (p == 0) {
		printf("�޸� ����!\n");
		return -100;
	}
	p = (char*)malloc(200); // ----> ������ �Ҵ���� ������ �̾ư� �Ǿ����. // ���� �ݺ��� �ȿ� ������ ���α׷��� õõ�� ����.
	free(p); // �Ҵ���� ������ �ü������ ��ȯ, ����� ������

	// dangling pointer problem
	char* p = (char*)malloc(100);
	char* q = p;
	free(q); // q�� �ݳ��� �ع���

	*p = 20; // �̹� �ݳ��� ������ ������ �Ϸ���. (���� ������ 2�� �̻��� ���α׷��� ���� ���ư�.)


	return 0;
}
#endif


// p. 96 ����ü�� ������
#if 1
typedef struct {
	int a;
	char b;
} AAA;

int main(void) {
	AAA a;
	a.a = 10;
	a.b = 'a';


	AAA* pa; // ����ü�� �����Ϳ� �ִ� �ɷ� �����÷���, ->�� �̿��Ѵ�.
	pa = &a;
	pa->a = 40;
	pa->b = 'c';

	pa = (AAA*)malloc(sizeof(AAA));
	pa->a = 50;
	pa->b = 'd';
	free(pa);



	return 0;
}
#endif


// Chapter 4
// Stack LIFO(Last In First Out)

// ����?
// �ԷµǴ� ������ �����ϴ� stack�� ������ ����!!
//
// �Է� : push <--- stack�� ���� �����ϴ� operation
// ��� : pop  <--- stack���� ���� ������ operation
// ���� �ɶ��� 1���� �迭�� ������ �ȴ�.


#if 0
#define STACK_SZ 10 // 10�� ������ push�Ǵ� stack

int stack[STACK_SZ];
int top = -1; // ���� ������ �� ����� ��ġ index // ó������ �ƹ��͵� ���⿡ -1

// stack�� full���� �˻�
// full ----> 1�� ��ȯ
// �ƴϸ� ----> 0�� ��ȯ
int isFull(void) {
	return	(top == (STACK_SZ - 1)); //���� �������̱� ������ �� ->1, ����->0
}

// stack�� ����ִ��� Ȯ��
// 1 : ���������,
// 0 : �ƴϸ�
int isEmpty(void) {
	return (top == -1);
}
// push, pop
void push(int _v) {
	
	if (isFull()) { // �� �̻� push�� �Ұ���
		printf("����, stack is full!!\n");
		return;
	}
	top++;
	stack[top] = _v;

	return;
}

int pop(void) {
	
	// 1% ���� ���� �Ͼ�� ���� ��Ȳ
	if (isEmpty()) {
		printf("���� empty\n");
		return -999; // -999�� ������Ȳ�� ��Ÿ���� Ư�����ڶ�� ����
	}
	// 99% Ȯ���� �Ͼ�� ��
	int result = stack[top]; // ������ �߿���.
	top--;
	return result;

}

int main(void) {

	push(4);
	push(5);
	push(6);
	push(7);

	pop();
	printf("%d\n", pop()); // ==> �ùٸ��� ������ �����Ǿ��ٸ�, 6
	return 0;
}
#endif







