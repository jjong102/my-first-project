//--------------------------------------------------------------
// stack, LIFO (last in fast out) 
// 
// postfix ���
// �츮�� ����ϴ� ���� : 2 + 3, infix
//	 operator ��ġ ����
// ��ǻ�Ͱ� ����� ���� postfix ���¸� ���
//	 2 + 3 --> 2 3 +
// 
// postfix�� ����
// - ��ȣ�� ������� �ʰ� �켱���� ǥ�Ⱑ ����
// 
// 2 + 3 * 5 ---> 2 3 5 * +
// (2 + 3) * 5 (infix������ ��ȣ�� ���� ����� ����)
// �׷���,
// postfix������
// (2 + 3) * 5 ---> 2 3 + 5 * (��ȣ ���̵� ǥ�� ����)
// 
// postfix�� ��� 
//		���ʿ��� ���������� �о� �����鼭,
//		������ (+,- ...) ������ ���� 2�� ���ڷ� ��� --> ���ڷ� ġȯ
//		������ ���� ������ �ݺ�
// 
// ����� infix�� �Է�
// ��ǻ�ʹ� 1) infix --> postfix�� ��ȯ
//         2) posetfix�� ���	(�Ѵ� stack�� ����Ͽ� ���)
// 
// postfix ���� ���
//		������ ������ �ϱ� ���ؼ� 1�ڸ� ����
//		4Ģ����, +,-,*,/, ������ ���
//		���迡 ������� �Է�
// 
// stack�� �̿��ؼ� �����ϴ� �˰���
//		stack�� �ϳ� �����ϰ�,
//		������ ���ʿ��� ���������� �о�鼭
//		���ڸ�, stack�� push
//		�����ڸ�, stack���� 2���� pop�ϰ�, ����ؼ� �ٽ� push
//		���� ���� ������ ���
//--------------------------------------------------------------


#if 1

#include <stdio.h>
#define STACK_SZ 20

int stack[STACK_SZ]; // stack ����, ������ �����ϴ� ����
int top = -1; // �� ���� ����� ���� ��ġ (index) {


// push, pop, isFull, isEmpty
int isFull() {
	return (top == (STACK_SZ - 1));
}

int isEmpty() {
	return (top == -1);
}

void push(int _v) {
	// ����,full 
	if (isFull()) {
		printf("�̫��� ?? \n");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}

int pop(void) {
	if (isEmpty()) {
		printf("�����̼�\n");
		return -999; // -999�� ����ٴ� Ư���� ��,, ���� �ƴ�
	}
	int result = stack[top];
	top--;
	return result;
}


// v1�� v2�� �޾Ƽ�, op ������ �� ����� ��ȯ
// op : +, -, *, /
int calc_expr(char op, int v1, int v2) {

	switch (op) {
		case '+':
			return (v1 + v2);
		case '-':
			return (v2 - v1); // ���� ����	
		case '*':
			return (v1 * v2);
		case '/':
			return (v2 / v1); // ���� ����	

	}
}



int main(void) {



	char postfix[] = "775*/"; //postfix expression
	int idx = 0; //expression���� ���� �д� ��ġ
	
	// ���ʿ��� ���������� �ѱ��ھ� �д� �ڵ�
	// expression���� ������ ������.... \0�� expression ���� null�� �ǹ�
	while (postfix[idx] != '\0') {
		
		// ����, ������, �� �� �ϳ��� ���´�.
		
		// ������ ��� ó��
		char _c = postfix[idx]; // �ϴ� ����, �̰� ���ص� ������...
		if ((_c >= '0') && (_c <= '9')) { //���� Ȯ��
			push((int)(_c - '0')); // '0'�� �������� ������̱� ������ ���ڰ� ���´�. ex) 103('3') - 100('0') = 3
		}
		else { // ���� �Ƚ�, ���� �ƴϸ� ������ 4���� �ϳ� ���´ٰ� ����!!
			   // �׷���, �̷��� ¥�� �ȵ�...!
			
			// _c�� ������,
			int v1 = pop();
			int v2 = pop();
			int res = calc_expr(_c, v1, v2);
			push(res);

		}
		idx++;
	}

	// ���⿡ �Դٸ�, ���ÿ��� ���� 1���� �־�� ��!!
	printf("���� ����� %d \n", pop());




	return 0;
}
#endif