//-------------------------------------------------------------
// infix���� postfix ������
// 
// stack �̿�
// 
// �˰���
// ������: ���� ������ �ȹٲ�
// ���ʿ��� ���������� 1���ھ� �о���鼭,
// ���ڸ� ���
// �����ڸ� ??? 
//	 - �⺻������ push 
//	 - ��, ������ ��������� ���� ���� ������
//	    	�ƴϸ�, ������� ���� ���� ������ push
//				ex) 1 + 2 - 3 * 5 ---> 1 2 + 3 5 * -
//	 - ��ȣ�� ���Դ�. 2���� ����, ���� ��ȣ (, �ݴ� ��ȣ ) [ )�� stack�� ���� ���� �ƴ��Ѵ�.]
//     .. ���� ��ȣ�� ������ push
//	   .. ���� ��ȣ�� �켱������ �������� ���
//	   .. �ݴ� ��ȣ�� ������, ���� ��ȣ ���ʳ��� ������ pop�ϸ鼭 ������ ���		
//-------------------------------------------------------------

#if 0
#include <stdio.h>
#define STACK_SZ 20

char stack[STACK_SZ]; // stack ����, ��ȣ�� ���� ����
int top = -1; // �� ���� ����� ���� ��ġ (index) {


// push, pop, isFull, isEmpty
int isFull() {
	return (top == (STACK_SZ - 1));
}

int isEmpty() {
	return (top == -1);
}

void push(char _v) {
	// ����,full 
	if (isFull()) {
		printf("�̫��� ?? \n");
		return;
	}
	top++;
	stack[top] = _v;
	return;
}

char pop(void) {
	if (isEmpty()) {
		printf("�����̼�\n");
		return '\0'; // '\0'�� ����ٴ� Ư���� ��,, ������ �ƴ�
	}
	char result = stack[top];
	top--;
	return result;
}

int amIHigher(char _c) {

	if (stack[top] == '(') { // ȣ�� ���̽�
		return 1;
	}
	else if (_c == '*' || _c == '/') {
		if (stack[top] == '+' || stack[top] == '-c') {
			return 1;
		}
	}
	// _c�� +, - �� ���� �켱������ ���� ���� ����.
	return 0;
	
}



// ����
// ���ڴ� ���ڸ�
// �������.
int main(void) {

	char infix_expr[] = "1*(2+3)"; // == > 1 2 3 + *
	int idx = 0; //���� ��� �ϰ� �ִ��� ǥ��

	while (infix_expr[idx] != '\0') {
		char _c = infix_expr[idx];
		// 1. ���ڸ� ���, happy case
		if ((_c >= '0') && (_c <= '9')){
			printf("%c", _c);
		}
		else { // ������, (, ) -�� �� �߿� �ϳ�
			if (_c == '(') {
				push(_c);
			}
			else if (_c == ')') { //�ݴ� ��ȣ��, ���� ��ȣ ���� ������ pop�ϸ鼭 ������ ���
				while (1) {
					char _d = pop();
					if (_d == '(') { // Ż�� ����
						break; // �� �̻� pop�� ���� �ʰ�, �Ѿ��.
					}
					printf("%c", _d);
				}
			}
			else { // +, -, *, /
				// ��. ������ ����ִ� --> thank you case, push�� �ϸ� �Ǵϱ�....
				// ��. ������ �� ����ִµ�, (�� �� ���̾�, --> thank, push�� �ϸ� �Ǵϱ�...
				// ��. ������ �� ����ִµ�, ������ �켱������ ������ �ϴ� ���, --> �λ����̽�
				if (isEmpty()) { // ��. ���
					push(_c);
				}
				else { //��, �� ��� ó�� : ������ �� ����ִ� ���
					// _c�� stack[top]�� �켱������ ������,
					// _c�� ������ --> push : �׳��� thank you
					//		������ --> ���� �ֵ� �� pop�ؼ� ����ϰ�, puxh --> ��� ���̽�
					// amIHigher(_c) �Լ� : _c�� �켱������ stack[top]���� ������ 1, �ƴϸ� 0
					while (1) {
						if (!amIHigher(_c)) {
							printf("%c", pop());
						}
						else {
							break;
						}
						
					}
					push(_c);
				}
			}

		}




		idx++;
	}

	// �� �ϰ� ����, ������ �ؾ� �ϳ���?
	// ������ empty�� ������, pop�ϸ鼭 ���
	while (isEmpty() != 1) {
		printf("%c", pop());
	}

	printf("\n");
	return 0;
}
#endif